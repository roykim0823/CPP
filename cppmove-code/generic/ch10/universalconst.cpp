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

void iterate(std::string::iterator beg, std::string::iterator end)
{
  std::cout << "do some non-const stuff with the passed range\n";
}

void iterate(std::string::const_iterator beg, std::string::const_iterator end)
{
  std::cout << "do some const stuff with the passed range\n";
}

template<typename T>
void process(T&& coll)
{
  iterate(coll.begin(), coll.end());  // coll is not perfect forwarding!
}

int main()
{
  std::string v{"v"};
  const std::string c{"c"};

  process(v);                 // coll binds to a non-const lvalue, iterators passed
  process(c);                 // coll binds to a const lvalue, const_iterators passed
  process(std::string{"t"});  // coll binds to a non-const prvalue, iterators passed
  process(std::move(v));      // coll binds to a non-const xvalue, iterators passed
  process(std::move(c));      // coll binds to a const xvalue , const_iterators passed
}

