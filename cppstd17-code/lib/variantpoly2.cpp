//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <type_traits>

int main()
{
  using Var = std::variant<int, double, std::string>;

  std::vector<Var> values {42, 0.19, "hello world", 0.815};

  for (const Var& val : values) {
    std::visit([] (const auto& v) {
                 if constexpr(std::is_same_v<decltype(v),
                              const std::string&>) {
                   std::cout << '"' << v << "\" ";
                 }
                 else {
                   std::cout << v << ' ';
                 }
               },
               val);
  }
}

