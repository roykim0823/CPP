#include <atomic>
#include <mutex>
#include <iostream>
#include <thread>

class spinlock_mutex
{
    std::atomic_flag flag;
public:
    spinlock_mutex(): flag(ATOMIC_FLAG_INIT) {}

    void lock() {
        while(flag.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

spinlock_mutex mutex;

void func() {
    std::lock_guard<spinlock_mutex> lg(mutex);
    std::cout << "hello" << std::endl;
    std::this_thread::sleep_for(std::chrono::microseconds(500));
}

int main() {
    std::thread a(func);
    std::thread b(func);
    std::thread c(func);
    a.join();
    b.join();
    c.join();
}