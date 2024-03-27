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


#include <string>

struct alignas(32) MyType32 {
  int i;
  char c;
  std::string s[4];
  //...
};

int main()
{
  auto p = new MyType32;  // allocates 32-byte aligned memory since C++17
  //...
  delete p;
}

