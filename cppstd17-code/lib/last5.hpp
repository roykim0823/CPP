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


#ifndef LAST5_HPP
#define LAST5_HPP

#include <iterator>
#include <iostream>

template<typename T>
void printLast5(const T& coll)
{
  // compute size:
  auto size{std::size(coll)};
  // advance to the position starting at the last 5 elements
  std::cout << size << " elems: ";
  auto pos{std::begin(coll)};
  if (size > 5) {
    std::advance(pos, size - 5);
    std::cout << "... ";
  }
  // print remaining elements:
  for ( ; pos != std::end(coll); ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
}

#endif // LAST5_HPP


