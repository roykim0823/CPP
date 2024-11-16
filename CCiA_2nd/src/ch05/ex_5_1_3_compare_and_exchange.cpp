#include <atomic>
#include <iostream>
#include <thread>

void run_code(int expected_value) {
    std::atomic<int> x(20);

    std::cout << "previous expected value - " << expected_value << std::endl;
    bool return_val = x.compare_exchange_weak(expected_value, 6);  // no gurantee to exchange

    std::cout << "operation successful    - " << (return_val ? "yes" : "no") << std::endl;
    std::cout << "current expected value  - " << expected_value << std::endl;
    std::cout << "current x               - " << x.load() << std::endl;
}

void run_code2(int expected_value) {
    std::atomic<int> x(20);

    std::cout << "previous expected value - " << expected_value << std::endl;
    bool return_val = x.compare_exchange_strong(expected_value, 6);  // no gurantee to exchange

    std::cout << "operation successful    - " << (return_val ? "yes" : "no") << std::endl;
    std::cout << "current expected value  - " << expected_value << std::endl;
    std::cout << "current x               - " << x.load() << std::endl;
}

int main() {
    run_code(20);
    run_code(10);
    std::cout << std::endl;
    run_code2(20);
    run_code2(10);
    
    return 0;
}