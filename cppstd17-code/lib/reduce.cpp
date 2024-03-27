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


#include <array>
#include <iostream>
#include <numeric>

int main()
{
  std::array coll{3, 1, 7, 5, 4, 1, 6, 3};

  // process sum of elements
  std::cout << "sum: "
       << std::reduce(coll.cbegin(), coll.cend())  // range
       << '\n';

  // process sum of elements with initial value:
  std::cout << "sum: "
       << std::reduce(coll.cbegin(), coll.cend(),  // range
                      0)                           // initial value
       << '\n';

  // process product of elements
  std::cout << "product: "
       << std::reduce (coll.cbegin(), coll.cend(),  // range
                       1LL,                         // initial value
                       std::multiplies{})           // operation
       << '\n';

  // process product of elements (use 0 as initial value)
  std::cout << "product: "
       << std::reduce (coll.cbegin(), coll.cend(),  // range
                      0,                            // initial value
                      std::multiplies{})            // operation
       << '\n';
}

