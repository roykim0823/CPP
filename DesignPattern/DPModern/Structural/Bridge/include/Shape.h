#include <iostream>
#include "Renderer.h"
using namespace std;

// two classes of objects

// Renderers - determine how an object is drawn
// Shapes - determine what to draw

struct Shape
{
protected:
  Renderer& renderer;
  Shape(Renderer& renderer) : renderer{ renderer } {}
public: virtual void draw() = 0; // implementation specific
  virtual void resize(float factor) = 0; // abstraction specific
};

struct Circle : Shape
{
  float x, y, radius;

  void draw() override
  {
    renderer.render_circle(x, y, radius);
  }

  void resize(float factor) override
  {
    radius *= factor;
  }

  Circle(Renderer& renderer, float x, float y, float radius)
    : Shape{renderer},
      x{x},
      y{y},
      radius{radius}
  {
  }
};

