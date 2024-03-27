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


#include <utility>     // for std::invoke()
#include <functional>  // for std::forward()

template<typename Callable, typename... Args>
void call(Callable&& op, Args&&... args)
{
  //...
  std::invoke(std::forward<Callable>(op),    // call passed callable with
              std::forward<Args>(args)...);  // all additional passed args
}

