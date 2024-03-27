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


#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "coord.hpp"
#include <iostream>

class Rectangle {
  private:
    Coord from;
    Coord to;
  public:
    Rectangle (Coord f, Coord t)
     : from{f}, to{t} {
    }

    void move(const Coord& c) {
      from += c;
      to += c;
    }

    void draw() const {
      std::cout << "rectangle from " << from
                << " to " << to << '\n';
    }
};

#endif

