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
#include <map>

int main()
{
  std::map<long, std::string> coll;

  for (int i=0; i<10; ++i) {
    std::string s{"Customer" + std::to_string(i)};
    coll.emplace(i, s);
  }

  // print element distances:
  for (const auto& elem : coll) {
    static long long lastVal = 0;
    long long val = reinterpret_cast<long long>(&elem);
    std::cout << "diff: " << (val-lastVal) << '\n';
    lastVal = val;
  }
}

