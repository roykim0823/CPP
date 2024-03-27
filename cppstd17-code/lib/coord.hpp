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


#ifndef COORD_HPP
#define COORD_HPP

#include <iostream>

class Coord {
  private:
    int x;     // x coordinate
    int y;     // y coordinate
  public:
    // default constructor:
    Coord() : x{0}, y{0} {
    }
    // other constructor:
    Coord(int newx, int newy) : x{newx}, y{newy} {
    }

    friend Coord operator+ (Coord c1, Coord c2) {  // plus
      return Coord{c1.x+c2.x, c1.y+c2.y};
    }
    friend Coord operator- (Coord c1, Coord c2) {  // diff
      return Coord{c1.x-c2.x, c1.y-c2.y};
    }
    Coord operator- () const {                     // negate
      return Coord{-x, -y};
    }
    void operator+= (Coord c) {                    // +=
      *this = *this + c;  // or: x+=c.x, y+=c.y
    }
    void operator-= (Coord c) {                    // +=
      operator+=(-c);     // or as above
    }

    int getX() const {
      return x;
    }
    int getY() const {
      return y;
    }
    friend std::ostream& operator<< (std::ostream& strm, Coord c) {
      return strm << '(' << c.x << ',' << c.y << ')';
    }
};

#endif

