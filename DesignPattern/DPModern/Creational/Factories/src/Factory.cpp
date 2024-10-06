#include <cmath>
#include <iostream>

class Point
{
  // private constructor -> use a factory method
  Point(float x, float y) : x(x), y(y){}
  float x, y;
public:


  friend class PointFactory;  // Violate OCP

  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
  	return os
    	<< "x: " << obj.x
    	<< " y: " << obj.y;
  }
};

class PointFactory
{
public:
  static Point NewCartesian(float x, float y)
  {
    return Point{ x,y };
  }

  static Point NewPolar(float r, float theta)
  {
    return Point{ r*cos(theta), r*sin(theta) };
  }
};

int main() {
	auto my_point = PointFactory::NewCartesian(3, 4);
	std::cout << my_point << std::endl;
	return 0;
}
