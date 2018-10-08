#include <cmath>

enum class PointType
{
  cartesian,
  polar
};

class Point
{
	// no longer afford telling the user what co-ordinate system those vlaues should come from
  Point(float a, float b, PointType type = PointType::cartesian)
  {
    if (type == PointType::cartesian)
    {
      x = a; b = y;
    } 
    else
    {
      x = a*cos(b);
      y = a*sin(b);
    }
  }

  // use a factory method
  Point(float x, float y) : x(x), y(y){}
public:
  float x, y;

};
