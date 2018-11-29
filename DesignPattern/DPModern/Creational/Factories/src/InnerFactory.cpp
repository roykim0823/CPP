#include <cmath>
#include <iostream>

class Point
{
  // private constructor -> use a factory method
  Point(float x, float y) : x(x), y(y) {}

  // inner factory class: used in C#, Java those do not have 'friend'
  class PointFactory
  {
    PointFactory() {}
  public:
    static Point NewCartesian(float x, float y)
    {
      return { x,y };
    }
    static Point NewPolar(float r, float theta)
    {
      return{ r*cos(theta), r*sin(theta) };
    }
  };
public:
  float x, y;
  static PointFactory Factory;  // simplify calling name

  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
  	return os
    	<< "x: " << obj.x
    	<< " y: " << obj.y;
  }

};

int main()
{
  // will not work
  // Point p{ 1,2 };

  // nope!
  // Point::PointFactory pf;

  // if factory is public, then
  //auto p = Point::PointFactory::NewCartesian(3, 4);

  // at any rate, use this
  auto pp = Point::Factory.NewCartesian(2, 3);
  std::cout << pp << std::endl;

  return 0;
}
