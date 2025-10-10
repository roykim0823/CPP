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
#include <utility>  // for std::move()

struct MyStruct {
  int i = 0;
  std::string s;
};

MyStruct getStruct() {
  return MyStruct{42, "hello"};
}

int main() {
  MyStruct ms;
  auto [u, v] = ms;  // structured bindings

  auto [id, val] = getStruct();
}
