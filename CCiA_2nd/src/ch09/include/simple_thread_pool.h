#pragma once
#include <atomic>
#include <future>
#include <thread>
#include <type_traits>
#include <vector>

#include "common.h"
#include "thread_safe_queue.h"

// Listing 9.1 Simple thread pool
template <typename T>
class BaseThreadPool {
protected:
    std::atomic_bool done;
    threadsafe_queue<T> work_queue;
    std::vector<std::thread> threads;
    join_threads joiner;

    virtual void worker_thread() {
        while(!done) {
            T task;
            if(work_queue.try_pop(task)) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }

public:
    BaseThreadPool(): done(false), joiner(threads) {
        unsigned const thread_count=std::thread::hardware_concurrency();
        std::cout << "Thread Count: " << thread_count << std::endl;
        try {
            for(unsigned i=0; i<thread_count; ++i) {
                threads.push_back(std::thread(&BaseThreadPool::worker_thread,this));
            }
        } catch(...) {
            done=true;
            throw;
        }
    }

    ~BaseThreadPool() {
        done=true;
    }
};

template <typename T>
class SimpleThreadPool: public BaseThreadPool<T> {
public:
    SimpleThreadPool() = default;
    template<typename FunctionType>
    void submit(FunctionType f)
    {
        this->work_queue.push(T(f));
    }
};


// Listing 9.2 A thread pool with waitable task
template <typename T>
class ThreadPoolWait: public BaseThreadPool<T> {
public:
    template<typename FunctionType>
    std::future<typename std::invoke_result<FunctionType()>::type>
    submit(FunctionType f) {
        typedef typename std::invoke_result<FunctionType()>::type result_type;
        std::packaged_task<result_type> task(std::move(f));
        std::future<result_type> res(task.get_future());
        this->work_queue.push(std::move(task));
        return res;
    }

    // Listing 9.4 An implementation of run_pending_task()
    void run_pending_task() {
        T task;
        if(this->work_queue.try_pop(task)) {
            task();
        } else {
            std::this_thread::yield();
        }
}
};

// Listing 9.6 A thread pool with thread-local work queue
template <typename T>
class ThreadPoolWaitLocalQueue: public BaseThreadPool<T> {
private:
    typedef std::queue<T> local_queue_type;  // lockfree for local queue
    static thread_local std::unique_ptr<std::queue<T>> local_work_queue;
protected:
    void worker_thread() override {
        local_work_queue.reset(new local_queue_type);

        while(!this->done) {
            run_pending_task();
        }
    }

public:
    template<typename FunctionType>
    std::future<typename std::invoke_result<FunctionType()>::type>
    submit(FunctionType f) {
        typedef typename std::invoke_result<FunctionType()>::type result_type;

        std::packaged_task<result_type()> task(f);
        std::future<result_type> res(task.get_future());
        if(local_work_queue) {
            local_work_queue->push(std::move(task));
        } else {
            this->work_queue.push(std::move(task));
        }
        return res;
    }

    void run_pending_task() {
        function_wrapper task;
        if(local_work_queue && !local_work_queue->empty()) {
            task=std::move(local_work_queue->front());
            local_work_queue->pop();
            task();
        } else if(this->work_queue.try_pop(task)) {
            task();
        } else {
            std::this_thread::yield();
        }
    }
};

// define the static member variable
template <typename T>
thread_local std::unique_ptr<std::queue<T>> ThreadPoolWaitLocalQueue<T>::local_work_queue=nullptr;
