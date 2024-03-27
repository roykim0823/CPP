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


#include <variant>
#include <iostream>

int main()
{
  std::variant<int, std::string> var{"hi"};  // initialized with string alternative
  std::cout << var.index() << '\n';          // prints 1
  var = 42;                                  // now holds int alternative
  std::cout << var.index() << '\n';          // prints 0
  //...
  try {
    int i = std::get<0>(var);                    // access by index
    std::string s = std::get<std::string>(var);  // access by type (throws exception here)
    //...
  }
  catch (const std::bad_variant_access& e) {     // in case a wrong type/index is used
    std::cerr << "EXCEPTION: " << e.what() << '\n';
    //...
  }
}

