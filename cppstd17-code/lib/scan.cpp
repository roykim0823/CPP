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
#include <iostream>
#include <iterator>
#include <array>

int main()
{
  std::array coll{3, 1, 7, 0, 4, 1, 6, 3};

  std::cout << " inclusive_scan():    ";
  std::inclusive_scan(coll.begin(), coll.end(),
                      std::ostream_iterator<int>(std::cout, " "));

  std::cout << "\n exclusive_scan():  ";
  std::exclusive_scan(coll.begin(), coll.end(),
                      std::ostream_iterator<int>(std::cout, " "),
                      0);  // mandatory

  std::cout << "\n exclusive_scan():  ";
  std::exclusive_scan(coll.begin(), coll.end(),
                      std::ostream_iterator<int>(std::cout, " "),
                      100);  // mandatory

  std::cout << "\n inclusive_scan():      ";
  std::inclusive_scan(coll.begin(), coll.end(),
                      std::ostream_iterator<int>(std::cout, " "),
                      std::plus{}, 100);

  std::cout << "\n exclusive_scan():  ";
  std::exclusive_scan(coll.begin(), coll.end(),
                      std::ostream_iterator<int>(std::cout, " "),
                      100, std::plus{});  // note: different order
}

