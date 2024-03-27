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

#include "geoobj.hpp"
#include <iostream>

class Circle : public GeoObj {
 private:
  Coord center;
  int radius;
 public:
  Circle (std::string n, Coord c, int r)
   : GeoObj{std::move(n)}, center{c}, radius{r} {
  }

  void move(Coord c) {
    center += c;
  }
  void draw() const {
    std::cout << "circle '" << name << "' at " << center
              << " with radius " << radius << '\n';
  }
};

#endif

