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


#include "pmrcustomer.hpp"
#include "tracker.hpp"
#include <vector>

int main()
{
  Tracker tracker;
  std::pmr::vector<PmrCustomer> coll(&tracker);
  coll.reserve(100);                     // allocates with tracker 

  PmrCustomer c1{"Peter, Paul & Mary"};  // allocates with get_default_resource()
  coll.push_back(c1);                    // allocates with vector allocator (tracker)
  coll.push_back(std::move(c1));         // copies (allocators not interchangeable)

  for (const auto& cust : coll) {
    std::cout << cust.getName() << '\n';
  }
}

