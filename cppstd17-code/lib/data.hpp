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


#ifndef DATA_HPP
#define DATA_HPP

#include <iterator>
#include <iostream>

template<typename T>
void printData(const T& coll)
{
  // print every second element:
  for (std::size_t idx{0}; idx < std::size(coll); ++idx) {
    if (idx % 2 == 0) {
      std::cout << std::data(coll)[idx] << ' ';
    }
  }
  std::cout << '\n';
}

#endif // DATA_HPP


