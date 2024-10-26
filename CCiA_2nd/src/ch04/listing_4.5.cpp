#include <mutex>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <memory>
#include <thread>

template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadsafe_queue() {}
    threadsafe_queue(threadsafe_queue const& other) {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queue=other.data_queue;
    }

    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        std::cout << "push(" << new_value << ")" << std::endl;
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        value=data_queue.front();
        data_queue.pop();
        std::cout << "void wait_and_pop(" << value << ")" << std::endl;
    }

    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        std::cout << "std::shared_ptr<T> wait_and_pop(" << *res << ")" << std::endl;
        return res;
    }

    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return false;
        value=data_queue.front();
        data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop() {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

void producer(threadsafe_queue<int>& ts_q) {
    ts_q.push(1);
    ts_q.push(2);
    ts_q.push(3);
    ts_q.push(4);
    ts_q.push(5);
}

void consumer(threadsafe_queue<int>& ts_q) {
    std::vector<int> answer;
    answer.push_back(*ts_q.wait_and_pop());
    answer.push_back(*ts_q.wait_and_pop());
    int k;
    ts_q.wait_and_pop(k);
    answer.push_back(k);
    answer.push_back(*ts_q.wait_and_pop());
    answer.push_back(*ts_q.wait_and_pop());
}

int main() {
    threadsafe_queue<int> ts_queue;
    std::thread t1(producer, std::ref(ts_queue));
    std::thread t2(consumer, std::ref(ts_queue));
    t1.join();
    t2.join();
    return 0;
}
