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
#include <iostream>
#include <cassert>
#include <map>

struct MyStruct {
  int i = 0;
  std::string s;
};

MyStruct getStruct() {
  return MyStruct{42, "hello"};
}

std::tuple<char, float, std::string> getTuple() {
  return {'c', 10.0f, "tuple"};
}

int main() {
  {
  MyStruct ms {42, "hello"};

  auto [u, v] = ms;
  ms.i = 77;
  std::cout << u << std::endl;  // print 42
  u = 99;
  std::cout << ms.i << std::endl;  // print 77

  auto [u2, v2] = getStruct();
  assert(&((MyStruct*)&u2)->s == &v2);  // OK
  }

  {
  // reference
  MyStruct ms {42, "hello"};
  auto &[u, v] = ms;
  ms.i = 77;
  std::cout << u << std::endl;  // print 77
  u = 99;
  std::cout << ms.i << std::endl;  // print 99

  // 'const' required: Ok, the lifetime of temp extended to the lifetime of the boudn struct
  const auto &[u2, v2] = getStruct();
  }

  {
  // move semantics
  MyStruct ms = {42, "Jim"};
  auto && [v, n] = std::move(ms);  // entity is rvalue reference to ms
  std::cout << "ms.s: " << ms.s << '\n'; // prints "Jim"

  std::string s = std::move(n); // moves ms.s to s
  std::cout << "ms.s: " << ms.s << '\n';  // prints unspecified value
  std::cout << "n: " << n << '\n';        // prints unspecified value
  std::cout << "s: " << s << '\n';        // prints "Jim"
  }

  {
  MyStruct ms = {42, "Jim"};
  auto [v, n] = std::move(ms);  // new entity with moved_from values from ms
  std::cout << "ms.s: " << ms.s << '\n';  // prints unspecified value
  std::cout << "n:    " << n << '\n';     // prints "Jim"

  std::string s = std::move(n); // moves ms.s to s
  n = "Lara";
  std::cout << "ms.s: " << ms.s << '\n';  // prints unspecified value
  std::cout << "n: " << n << '\n';        // prints "Lara""
  std::cout << "s: " << s << '\n';        // prints "Jim"
  }

  // Structured Binding can be Used, "public data members", "raw C-style arrays", "tuple-like objects"
  // 1. Structures and Classes
  {
    struct B {
      int a = 1;
      int b = 2;
    };

    struct D1 : B {

    };

    auto [x, y] = D1{};  // Okay

    struct D2 : B {
      int c = 3;
    };

    // All non-static data members must be members of the same class definition
    //auto [i, j, k] = D2{};  // Compile-Time Error
  }

  // 2. Raw Arrays
  {
    int arr[] = {47, 11};
    auto [x, y] = arr;
    // auto [z] = arr;  // Error
  }

  // 3. Tuple-like: std::pair, std::tuple, and std::array
  {
    std::array<int, 4> stdarr {1, 2, 3, 4};
    auto &[i, j, k, l] = stdarr;
    i += 10;  // modifies stdarr[0]

    std::tuple<char, float, std::string> tu{'c', 32.2f, "tuple"};
    auto [a, b, c] = tu;

    std::map<std::string, int> coll;
    auto [pos, ok] = coll.insert({"new", 42});
    if(!ok) {
      // if insert failed, handle error using iterator pos
    }

    // before C++17
    auto ret = coll.insert({"new", 42});
    if (!ret.second) {
      // if insert failed, handle error using interator ret.first
    }
  }

  // Assigning new Values to Structued Binding for pair and tuple
  {
    auto [a, b, c] = getTuple();  // a, b, c have types and values of returned tuple
    // ...
    std::tie(a, b, c) = getTuple();  // a, b, c get values of next returned tuple

    // For example
    // std::boyer_moore_searcher bm{sub.begin(), sub.end()};
    // for (auto [beg, end] = bm(text.begin(), text.end()); beg != text.end();
    //     std::tie(beg,end) = bm(end, text.end())) {
    //     ...
    // }
  }
  return 0;
}
