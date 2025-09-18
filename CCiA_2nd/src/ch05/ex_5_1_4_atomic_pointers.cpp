#include <atomic>
#include <iostream>
#include <thread>

void run_code() {
    int values[20];

    for (int i=0; i<20; ++i) {
        values[i] = i+1;
    }

    std::atomic<int*> x_ptr = values;
    std::cout << "atomic integer pointer lock free? "
        << (x_ptr.is_lock_free() ? "yes" : "no") << std::endl;

    int *y_ptr = values + 3;

    x_ptr.store(y_ptr);
    std::cout << "value referening to by pointer : " << *(x_ptr.load()) << std::endl;

    bool ret_val = x_ptr.compare_exchange_weak(y_ptr, values + 10);
    std::cout << "store operation successful : " << (ret_val? "yes" : "no") << std::endl;
    std::cout << "new value pointer by atomic pointer : " << *x_ptr << std::endl;
}

void run_code2() {
    int values[20];

    for (int i=0; i<20; ++i) {
        values[i] = i+1;
    }

    std::atomic<int*> x_ptr = values;
    std::cout << "1. After intialization value pointed by atomic pointer:       "
        << *x_ptr << std::endl;

    int *prev_ptr_1 = x_ptr.fetch_add(12);
    std::cout << "2. After fetch_add, previous value pointed by atomic pointer: "
        << *prev_ptr_1 << std::endl;
    std::cout << "2. After fetch_add, new value pointed by atomic pointer:      "
        << *x_ptr << std::endl;


    int *prev_ptr_2 = x_ptr.fetch_sub(3);
    std::cout << "3. After fetch_sub, previous value pointed by atomic pointer: "
        << *prev_ptr_2 << std::endl;
    std::cout << "3. After fetch_sub, new value pointed by atomic pointer:      "
        << *x_ptr << std::endl;

    ++x_ptr;  // same as x_ptr;
    std::cout << "4. After pre increment value pointed by atomic pointer:       "
        << *x_ptr << std::endl;
}

int main() {
    run_code();
    std::cout << std::endl;
    run_code2();
    return 0;
}