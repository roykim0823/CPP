#include "shape.h"
using namespace std;

// static decorator: mixin inheritance
// note: class, not typename
template <typename T> struct ColoredShape : T
{
  static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
  string color;

  // need this (or not!)-> gcc doesn't need it
  ColoredShape(){}

  template <typename...Args>
  ColoredShape(const string& color, Args ...args)
    : T(std::forward<Args>(args)...), color{color}
    // you cannot call base class ctor here
    // b/c you have no idea what it is
  {}

  string str() const override
  {
    ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape : T
{
  uint8_t transparency;
  template<typename...Args>
  TransparentShape(const uint8_t transparency, Args ...args)
    : T(std::forward<Args>(args)...), transparency{ transparency }
  {}

  string str() const override
  {
    ostringstream oss;
    oss << T::str() << " has "
      << static_cast<float>(transparency) / 255.f * 100.f
      << "% transparency";
    return oss.str();
  }
};

void constructor_forwarding()
{
  struct NotAShape
  {
    virtual string str() const { return string{}; }
  };

  // we don't want this to be legal, thus a static_assert above
  //ColoredShape2<NotAShape> legal;

  // no code completion for this case
  // can comment out argument, too! (default constructor)
  TransparentShape<Square> hidden_square{ 1, 2 };
  cout << hidden_square.str() << endl;

  ColoredShape<TransparentShape<Square>> sq = { "red", 51, 5 };
  cout << sq.str() << endl;
}

int main()
{
  constructor_forwarding();

  // won't work without a default constructor
  ColoredShape<Circle> green_circle{ "green", 5 };

  cout << green_circle.str() << endl;

  TransparentShape<ColoredShape<Square>> blue_invisible_square{ 0, "blue", 10 };
  blue_invisible_square.color = "blue";
  cout << blue_invisible_square.str() << endl;
  blue_invisible_square.side = 321;
  cout << blue_invisible_square.str() << endl;

  return 0;
}
