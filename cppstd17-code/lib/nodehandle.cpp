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
  std::map<int, std::string> m{{1, "mango"},
                               {2, "papaya"},
                               {3, "guava"}};

  auto nh = m.extract(2);  // nh has type decltype(m)::node_type
  nh.key() = 4; 
  m.insert(std::move(nh));

  for (const auto& [key, value] : m) {
    std::cout << key << ": " << value << '\n';
  }
}

