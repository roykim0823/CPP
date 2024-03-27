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


#ifndef LINE_HPP
#define LINE_HPP

#include "geoobj.hpp"
#include <iostream>

class Line : public GeoObj {
 private:
  Coord from;
  Coord to;
 public:
  Line (std::string n, Coord f, Coord t)
   : GeoObj{std::move(n)}, from{f}, to{t} {
  }

  void move(Coord c) {
    from += c;
    to += c;
  }
  void draw() const {
    std::cout << "line '" << name << "' from " << from
              << " to " << to << '\n';
  }
};

#endif

