#include <thread>
#include <utility>

class joining_thread {
    std::thread t;
public:
    joining_thread() noexcept=default;
    template<typename Callable, typename ... Args>
    explicit joining_thread(Callable&& func, Args&& ... args):
        t(std::forward<Callable>(func), std::forward<Args>(args)...)
    {}

    explicit joining_thread(std::thread t_) noexcept:
        t(std::move(t_))
    {}

    joining_thread(joining_thread&& other) noexcept:
        t(std::move(other.t))
    {}
    
    joining_thread& operator=(joining_thread&& other) noexcept {
        if(joinable())
            join();
        t=std::move(other.t);
        return *this;
    }

    joining_thread& operator=(std::thread other) noexcept {
        if(joinable())
            join();
        t=std::move(other);
        return *this;
    }
    ~joining_thread() noexcept {
        if(joinable())
            join();
    }
    void swap(joining_thread& other) noexcept {
        t.swap(other.t);
    }
    std::thread::id get_id() const noexcept {
        return t.get_id();
    }
    bool joinable() const noexcept {
        return t.joinable();
    }
    void join() {
        t.join();
    }
    void detach() {
        t.detach();
    }
    std::thread& as_thread() noexcept {
        return t;
    }
    const std::thread& as_thread() const noexcept {
        return t;
    }
};

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{}

void f()
{
    int some_local_state;
    joining_thread t({std::thread(func(some_local_state))});
        
    do_something_in_current_thread();
}

int main()
{
    f();
}
