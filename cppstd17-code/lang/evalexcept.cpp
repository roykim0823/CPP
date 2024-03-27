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

void print10elems(const std::vector<int>& v) {
  for (int i=0; i<10; ++i) {
    std::cout << "value: " << v.at(i) << '\n';
  }
}

int main()
{
  try {
    std::vector<int> vec{7, 14, 21, 28};
    print10elems(vec);
  }
  catch (const std::exception& e) {     // handle standard exception
    std::cerr << "EXCEPTION: " << e.what() << '\n';
  }
  catch (...) {                         // handle any other exception
    std::cerr << "EXCEPTION of unknown type\n";
  }
}

