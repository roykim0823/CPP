#include "shape.h"
using namespace std;

// we are not changing the base class of existing objects
// cannot make, e.g., ColoredSquare, ColoredCircle, etc.

struct ColoredShape : Shape
{
  Shape& shape;
  string color;

  ColoredShape(Shape& shape, const string& color)
    : shape{shape}, color{color}
  {}
  ColoredShape(Shape&& shape, const string& color)	
    : shape{shape}, color{color}
  {}

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape
{
  Shape& shape;
  uint8_t transparency;

  TransparentShape(Shape& shape, const uint8_t transparency)
    : shape{shape}, transparency{transparency}
  {}
  TransparentShape(Shape&& shape, const uint8_t transparency)
    : shape{shape}, transparency{transparency}
  {}

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has "
      << static_cast<float>(transparency) / 255.f*100.f
      << "% transparency";
    return oss.str();
  }
};

int main()
{
  Circle circle{ 5 };
  cout << circle.str() << endl;

  ColoredShape red_circle{ circle, "red" };
  cout << red_circle.str() << endl;

  //red_circle.resize(2); // oops

  TransparentShape red_half_visible_circle{ red_circle, 128 };
  cout << red_half_visible_circle.str() << endl;

  // Compose Both ColoredShape and TransparentShape
  // This requies R-value Reference
  TransparentShape myCircle { 
	  ColoredShape{ 
		  Circle{23}, "green" },
	  64
  };
  cout << myCircle.str() << endl;
  
  return 0;
}

