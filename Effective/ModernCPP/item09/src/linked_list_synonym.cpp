#include <list>
#include <memory>

/*
 *   Alias declarations may be templatized (typedefs cannot).
 *
 *   With alias declaration, dependent types no longer require
 *   to be preceded by typename (as does the cumbersome "::type" suffix).
 */
namespace alias {
class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                           // MyAllocList<T>
using MyAllocList = std::list<T, MyAlloc<T>>;  // is synonym for
                                               // std::list<T,
                                               //   MyAlloc<T>>

MyAllocList<Widget> lw;                        // client code

template<typename T>
class Widget_t {
private:
  MyAllocList<T> list;                         // no "typename",
  // ...                                       // no "::type"
};
}

/*
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container.
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container. In addition, dependent types
 *   must be preceded by typename.
 */

namespace typedef_ {
// typedef version
class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                      // MyAllocList<T>::type
struct MyAllocList {                      // is synonym for
  typedef std::list<T, MyAlloc<T>> type;  // std::list<T,
};                                        //   MyAlloc<T>>

MyAllocList<Widget>::type lw;             // client code

template<typename T>
class Widget_t {                            // Widget<T> contains
private:                                  // a MyAllocList<T>
  typename MyAllocList<T>::type list;     // as a data member
  // ...
};
}
