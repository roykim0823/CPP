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
#include "../tmpl/overload.hpp"


int main()
{
  using Var = std::variant<int, double, std::string>;

  std::vector<Var> values {42, 0.19, "hello world", 0.815};

  for (const auto& val : values) {
    std::visit(overload{
                 [] (auto v) {
                   std::cout << v << ' ';
                 },
                 [] (const std::string& v) {
                   std::cout << '"' << v << "\" ";
                 }
               },
               val);
  }
  {
    using namespace std;
     vector<variant<int, string>> vals {42, "hi", 8};
 for (const auto& v : vals) {
   visit(overload{
            [] (auto i) { cout << i << ' '; },
            [] (const string& s) { cout << '"' << s << "\" "; }
           },
           v);
 } 
  }
}

