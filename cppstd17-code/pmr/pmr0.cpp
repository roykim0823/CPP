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
#include <string>
#include <vector>
#include "../lang/tracknew.hpp"

int main()
{
  TrackNew::reset();

  std::vector<std::string> coll;
  for (int i=0; i < 1000; ++i) {
    coll.emplace_back("just a non-SSO string");
  }

  TrackNew::status();
}

