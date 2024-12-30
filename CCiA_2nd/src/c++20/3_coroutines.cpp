#include <coroutine>
#include <iostream>
#include <cassert>

#include "include/coroutines_class.h"

resumable foo() {
   std::cout << "a" << std::endl;
   co_await std::suspend_always();
   std::cout << "b" << std::endl;
   co_await std::suspend_always();
   std::cout << "c" << std::endl;
}


int main() {
   resumable res = foo();
   res.resume();
   while (res.resume());
}
