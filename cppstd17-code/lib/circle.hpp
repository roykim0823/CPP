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


#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "coord.hpp"
#include <iostream>

class Circle {
  private:
    Coord center;
    int rad;
  public:
    Circle (Coord c, int r)
     : center{c}, rad{r} {
    }

    void move(const Coord& c) {
      center += c;
    }

    void draw() const {
      std::cout << "circle at " << center
                << " with radius " << rad << '\n';
    }
};

#endif

