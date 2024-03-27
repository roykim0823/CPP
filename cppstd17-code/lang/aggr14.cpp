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


struct Derived;

struct Base {
 friend struct Derived;
 private: 
  Base() {
  }
};

struct Derived : Base {
};

int main()
{
  Derived d1{};    // ERROR since C++17
  Derived d2;      // still OK (but might not initialize)
}

