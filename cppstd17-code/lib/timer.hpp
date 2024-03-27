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


#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <string>
#include <chrono>


/********************************************
 * timer to print elapsed time
 ********************************************/

class Timer
{
  private:
    std::chrono::steady_clock::time_point last;
  public:
    Timer()
     : last{std::chrono::steady_clock::now()} {
    }
    void printDiff(const std::string& msg = "Timer diff: ") {
      auto now{std::chrono::steady_clock::now()};
      std::chrono::duration<double, std::milli> diff{now - last};
      std::cout << msg << diff.count() << "ms\n";
      last = std::chrono::steady_clock::now();
    }
};

#endif // TIMER_HPP

