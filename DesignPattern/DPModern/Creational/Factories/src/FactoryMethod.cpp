#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Point
{
protected: 
  // making the constructor protected
  Point(const float x, const float y)
    : x{x}, y{y}
  { }

public:
  float x, y;

  static Point NewCartesian(float x, float y)
  {
    return{ x,y };
  }
  static Point NewPolar(float r, float theta)
  {
    return{ r*cos(theta), r*sin(theta) };
  }
  
  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    return os
      << "x: " << obj.x
      << " y: " << obj.y;
  }
};

int main()
{
  auto p = Point::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;

  return 0;
}
