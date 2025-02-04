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


#include "tasksbugfix.hpp"
#include <iostream>
#include <chrono>
#include <exception>

int main()
{
  try {
    Tasks ts;
    ts.start([]{
               std::this_thread::sleep_for(std::chrono::seconds{2});
               std::cout << "\nt1 done" << std::endl;
             });
    ts.start([]{
               std::cout << "\nt2 done" << std::endl;
             });


    Tasks other{std::move(ts)};
  }
  catch (const std::exception& e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }

  try {
    Tasks ts;
    ts.start([]{
               std::this_thread::sleep_for(std::chrono::seconds{2});
               std::cout << "\nt1 done" << std::endl;
             });
    ts.start([]{
               std::cout << "\nt2 done" << std::endl;
             });

    Tasks other;
    other.start([]{
               std::this_thread::sleep_for(std::chrono::seconds{2});
               std::cout << "\nother t1 done" << std::endl;
             });
    other.start([]{
               std::cout << "\nother t2 done" << std::endl;
             });
    other = std::move(ts);

  }
  catch (const std::exception& e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }

}
