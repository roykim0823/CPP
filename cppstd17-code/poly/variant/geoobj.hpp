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


#ifndef GEOOBJ_HPP
#define GEOOBJ_HPP

#include "coord.hpp"
#include <string>

// abstract base class
class GeoObj
{
 protected:
  std::string name;

  GeoObj(std::string n)  // protected to make class abstract
   : name{std::move(n)} {
  }
 public:
  std::string getName() && {
    return std::move(name);
  }
  const std::string& getName() const& {
    return name;
  }
};

#endif

