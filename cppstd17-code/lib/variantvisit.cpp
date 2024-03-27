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


#include <variant>
#include <string>
#include <iostream>

struct MyVisitor
{
  void operator() (int i) const {
    std::cout << "int:    " << i << '\n';
  }
  void operator() (const std::string& s) const {
    std::cout << "string: " << s << '\n';
  }
  void operator() (long double d) const {
    std::cout << "double: " << d << '\n';
  }
};

int main()
{
  std::variant<int, std::string, long double> var(42);
  std::visit(MyVisitor(), var);  // calls operator() for int
  var = "hello";
  std::visit(MyVisitor(), var);  // calls operator() for string
  var = 42.7;
  std::visit(MyVisitor(), var);  // calls operator() for long double
}

