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


#include <iostream>
#include <variant>
#include <vector>
#include "coord.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

// common type of all geometric object types:
using GeoObj = std::variant<Line, Circle, Rectangle>;
  
// create and initialize a collection of geometric objects:
std::vector<GeoObj> createFigure()
{
  std::vector<GeoObj> f;
  f.push_back(Line{Coord{1,2},Coord{3,4}});
  f.push_back(Circle{Coord{5,5},2});  
  f.push_back(Rectangle{Coord{3,3},Coord{6,4}});  
  return f;
}

int main()
{
  std::vector<GeoObj> figure = createFigure();
  for (const GeoObj& geoobj : figure) {
    std::visit([] (const auto& obj) {
                 obj.draw();  // polymorphic call of draw()
               },
               geoobj);
  }
}

