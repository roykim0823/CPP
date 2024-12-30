#include <coroutine>
#include <memory>
#include <iostream>


#include "include/generators.h"

Generator<int> getNext(int start = 0, int step = 1) noexcept {
    auto value = start;
    for (int i = 0;; ++i) {
        co_yield value;
        value += step;
    }
}

int main() {

    std::cout << std::endl;

    std::cout << "getNext():";
    auto gen = getNext();
    for (int i = 0; i <= 10; ++i) {
        gen.next();
        std::cout << " " << gen.getValue();                      // (7)
    }

    std::cout << "\n\n";

    std::cout << "getNext(100, -10):";
    auto gen2 = getNext(100, -10);
    for (int i = 0; i <= 20; ++i) {
        gen2.next();
        std::cout << " " << gen2.getValue();
    }

    std::cout << std::endl;
}