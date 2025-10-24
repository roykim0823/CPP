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

class X {};

void f(const X&) {
  std::cout << "f(const X&) is called." << std::endl;
}

void f(X&&) {
  std::cout << "f(X&&) is called." << std::endl;
}

int main() {
  X v;
  const X c;
  f(v);
  f(c);
  f(X());
  f(std::move(v));

  return 0;
}
