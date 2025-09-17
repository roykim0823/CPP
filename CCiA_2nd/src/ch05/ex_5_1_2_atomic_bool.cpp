#include <atomic>
#include <iostream>
#include <thread>

void run_code() {
    std::atomic<bool> flag_1;
    std::cout << "flag_1 = " << flag_1 << std::endl;

    // std::atomic<bool> flag_2(flag_1);  // Cannot copy construct
    // std::atomic<bool> flag_3 = flag_1;  // Cannot copy assinable

    // Construct using non atomic boolean value
    bool non_atomic_bool = true;
    std::atomic<bool> flag_4(non_atomic_bool);
    std::cout << "flag_4 = " << flag_4 << std::endl;

    // assign non atomic boolean value
    std::atomic<bool> flag_5 = non_atomic_bool;
    std::cout << "flag_5 = " << flag_5 << std::endl;
}

void run_code2() {
    std::atomic<bool> x(false);
    std::cout << "atomic boolean is implemented lock free - "
              << (x.is_lock_free()? "yes" : "no") << std::endl;

    std::atomic<bool> y(true);
    x.store(false);
    x.store(y);
    std::cout << "value of the atomic bool y - " << y.load() << std::endl;

    bool z = x.exchange(false);  // exchange return the old value and set the new value.
    std::cout << "current value of atomic bool x - " << x.load() << std::endl;
    std::cout << "previous value of atomic bool x - " << z << std::endl;
}

int main() {
    run_code();
    run_code2();

    return 0;
}