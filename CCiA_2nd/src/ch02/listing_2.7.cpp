#include "include/listing_2_7_joining_thread.h"

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
