//********************************************************
// The following code example is taken from the book
//  C++ Move Semantics - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppmove.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include "sharedint.hpp"
#include <iostream>

int main()
{
  {
    SharedInt si1{42};
    SharedInt si2{si1};
    std::cout << si1.asString() << std::endl;  // si1 and si2 share the value
  }

  {
    SharedInt si1{42};
    SharedInt si2{std::move(si1)};
    std::cout << si1.asString() << std::endl;
    std::cout << si2.asString() << std::endl;
  }
}
