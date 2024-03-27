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
#include <vector> 
#include <string> 
#include <algorithm>  // for for_each_n()

int main()
{
  // initialize a vector of 10,000 string values:
  std::vector<std::string> coll;
  for (int i=0; i < 10000; ++i) {
    coll.push_back(std::to_string(i));
  }

  // modify first 5 elements:
  for_each_n(coll.begin(), 5,
             [] (auto& elem) {
               elem = "value" + elem;
             });

  // print first 10 elements:
  for_each_n(coll.begin(), 10,
             [] (const auto& elem) {
               std::cout << elem << '\n';
             });
}

