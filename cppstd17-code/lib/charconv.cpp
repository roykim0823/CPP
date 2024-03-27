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


#include "charconv.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

int main()
{
  std::vector<double> coll{0.1, 0.3, 0.00001};

  // create two slightly different floating-point values:
  auto sum1 = std::accumulate(coll.begin(), coll.end(),
                              0.0, std::plus<>());
  auto sum2 = std::accumulate(coll.rbegin(), coll.rend(),
                              0.0, std::plus<>());

  // look the same:
  std::cout << "sum1:  " << sum1 << '\n';
  std::cout << "sum1:  " << sum2 << '\n';

  // but are different:
  std::cout << std::boolalpha << std::setprecision(20); 
  std::cout << "equal: " << (sum1==sum2) << '\n';  // false !!
  std::cout << "sum1:  " << sum1 << '\n';
  std::cout << "sum1:  " << sum2 << '\n';
  std::cout << '\n';

  // check round-trip:
  d2str2d(sum1);
  d2str2d(sum2);
}

