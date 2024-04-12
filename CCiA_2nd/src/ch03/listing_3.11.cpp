#include <memory>
#include <mutex>

struct some_resource
{
    void do_something()
    {}
    
};


std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;
void foo()
{
    std::unique_lock<std::mutex> lk(resource_mutex);
    if(!resource_ptr)
    {
        resource_ptr.reset(new some_resource);
    }
    lk.unlock();
    resource_ptr->do_something();
}

// Alternative Implementation with call_once
std::once_flag resource_flag;
void init_resource() {
    resource_ptr.reset(new some_resource);
}
void foo_call_once() {
    std::call_once(resource_flag, init_resource);
    resource_ptr->do_something();
}

int main()
{
    foo();
}
