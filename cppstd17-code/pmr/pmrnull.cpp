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
#include <unordered_map>
#include <array>
#include <cstddef>  // for std::byte
#include <memory_resource>

int main()
{
  // use memory on the stack without fallback on the heap:
  std::array<std::byte, 200000> buf;
  std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size(),
                                           std::pmr::null_memory_resource()};

  // and allocate too much memory:
  std::pmr::unordered_map<long, std::pmr::string> coll {&pool};
  try {
    for (int i=0; i<buf.size(); ++i) {
      std::string s{"Customer" + std::to_string(i)};
      coll.emplace(i, s);
    }
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "BAD ALLOC EXCEPTION: " << e.what() << '\n';
  }
  std::cout << "size: " << coll.size() << '\n'; 
}

