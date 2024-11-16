#include <atomic>
#include <iostream>
#include <thread>

void run_code(std::atomic_flag& flag) {
    std::cout << "1. previous flag value: " << flag.test_and_set() << std::endl;
    std::cout << "2. previous flag value: " << flag.test_and_set() << std::endl;
    flag.clear();
    std::cout << "3. previous flag value: " << flag.test_and_set() << std::endl;
}

int main() {
    // std::atomic_flag flag1 = true;  // may cause compilation error
    std::atomic_flag flag2 = ATOMIC_FLAG_INIT;

    // run_code(flag1);
    run_code(flag2);

    return 0;
}