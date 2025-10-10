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


#include <string>
#include <utility>  // for std::move()

class Customer {
 private:
  std::string first;
  std::string last;
  long val;
 public:
  Customer (std::string f, std::string l, long v)
   : first{std::move(f)}, last{std::move(l)}, val{v} {
  }
  const std::string& firstname() const {
    return first;
  }
  std::string& firstname() {
    return first;
  }
  const std::string& lastname() const {
    return last;
  }
  std::string& lastname() {
    return last;
  }
  long value() const {
    return val;
  }
  long& value() {
    return val;
  }
};

