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


#include <iostream>
#include <string>

void process(const std::string&) {
  std::cout << "process(const std::string&)\n";
}
void process(std::string&) {
  std::cout << "process(std::string&)\n";
}
void process(std::string&&) {
  std::cout << "process(std::string&&)\n";
}

const std::string& computeConstLRef(const std::string& str) {
  return str;
}
std::string& computeLRef(std::string& str) {
  return str;
}
std::string&& computeRRef(std::string&& str) {
  return std::move(str);
}
std::string computeValue(const std::string& str) {
  return str;
}
const std::string computeConstValue(const std::string& str) {
  return str;
}
const std::string&& computeConstRRef(const std::string&& str) {
  return std::move(str);
}

int main()
{
  process(computeConstLRef("tmp"));      // calls process(const std::string&)

  std::string str{"lvalue"};
  process(computeLRef(str));             // calls process(std::string&)

  process(computeRRef("tmp"));           // calls process(std::string&&)
  process(computeRRef(std::move(str)));  // calls process(std::string&&)

  process(computeValue("tmp"));          // calls process(std::string&&)

  // disable move semantics
  process(computeConstValue("tmp"));
  process(computeConstRRef("tmp"));
}
