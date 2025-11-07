#include <complex>
#include <iostream>
#include <mutex>
#include <vector>
#include <typeinfo>

#include "type_name.hpp"

template<typename... Args>
auto make_vector(const Args&... elems) {
return std::vector{elems...};
}


int main() {
    // Before C++17
    {
        std::complex<double> c{5.1, 3.3};

        std::mutex mx;
        std::lock_guard<std::mutex> lg(mx);
    }

    // Since C++17
    {
        std::complex c{5.1, 3.3};

        std::mutex mx;
        std::lock_guard lg(mx);
    }

    std::vector v1{1, 2, 3};            // deduced as std::vector<int>
    std::vector v2{"hello", "world"};   // deduced as std::vector<const char*>
    std::cout << "v1 is " << typeid(v1).name() << '\n';
    std::cout << "v2 is " << typeid(v2).name() << '\n';
    std::cout << "v1 is " << type_name<decltype(v1)>() << '\n';
    std::cout << "v2 is " << type_name<decltype(v2)>() << '\n';

    std::vector v3(v1);
    std::vector v4 = {v1};
    auto v5 = std::vector{v1};
    std::cout << "v3 is " << type_name<decltype(v3)>() << '\n';
    std::cout << "v4 is " << type_name<decltype(v4)>() << '\n';
    std::cout << "v5 is " << type_name<decltype(v5)>() << '\n';

    std::vector vv{v1, v1};
    std::cout << "vv is " << type_name<decltype(vv)>() << '\n';

    std::vector<int> v{1, 2, 3};
    auto x1 = make_vector(v, v);    // vector<vector<int>>
    auto x2 = make_vector(v);       // vector<int> or vector<vector<int>>
    std::cout << "x1 is " << type_name<decltype(x1)>() << '\n';
    std::cout << "x2 is " << type_name<decltype(x2)>() << '\n';



    return 0;
}
