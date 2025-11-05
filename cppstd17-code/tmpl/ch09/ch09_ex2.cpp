
#include <iostream>
#include <vector>
#include <algorithm>

#include "classarglambda.hpp"

int main() {
    CountCalls sc([](auto x, auto y) {
        return x > y;
    });

    std::vector<int> v{1, 3, 2, 5, 4};
    std::cout << "before sorted " << sc.count() << " calls\n";
    std::sort(v.begin(), v.end(), std::ref(sc));
    std::cout << "sorted with " << sc.count() << " calls\n";

    auto fo = std::for_each(v.begin(), v.end(), CountCalls([](auto i) {
        std::cout << "elem: " << i << '\n';
    }));
    std::cout << "output with " << fo.count() << " calls\n";
}