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
#include <algorithm>  // for clamp()

int main()
{
  for (int i : {-7, 0, 8, 15}) {
    std::cout << std::clamp(i, 5, 13) << '\n';
  }
}

