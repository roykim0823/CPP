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


#include <numeric>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>

int main()
{
  std::array coll{3, 1, 7, 0, 4, 1, 6, 3};

  auto twice = [] (int v) { return v*2; };
  
  std::cout << " source:                      ";
  std::copy(coll.begin(), coll.end(),
            std::ostream_iterator<int>(std::cout, " "));

  std::cout << "\n transform_inclusive_scan():      ";
  std::transform_inclusive_scan(coll.begin(), coll.end(),
                                std::ostream_iterator<int>(std::cout, " "),
                                std::plus{}, twice);

  std::cout << "\n transform_inclusive_scan():      ";
  std::transform_inclusive_scan(coll.begin(), coll.end(),
                                std::ostream_iterator<int>(std::cout, " "),
                                std::plus{}, twice, 100);


  std::cout << "\n transform_exclusive_scan():  ";
  std::transform_exclusive_scan(coll.begin(), coll.end(),
                                std::ostream_iterator<int>(std::cout, " "),
                                100, std::plus{}, twice); // note the other param order
}

