#include <atomic>
#include <iostream>
#include <thread>



std::atomic<int> i = 0;
thread_local std::atomic<int> j = 0;

void foo() {
    ++i;
    std::cout << i;
}

void bar() {
    ++j;
    std::cout << j;
}

int main() {
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);

    t1.join();
    t2.join();
    t3.join();

    std::cout << std::endl;

	// Use thread local

	std::thread t4(bar);
    std::thread t5(bar);
    std::thread t6(bar);

	t4.join();
    t5.join();
    t6.join();

    std::cout << std::endl;
}