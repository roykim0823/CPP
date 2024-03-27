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

template<typename T>
void call(T op1, T op2)
{
  op1();
  op2();
}

void f1() {
  std::cout << "f1()\n";
}
void f2() noexcept {
  std::cout << "f2()\n";
}

int main()
{
  call(f1, f2);  // ERROR since C++17
}

