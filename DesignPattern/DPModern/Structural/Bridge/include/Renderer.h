#include <iostream>
using namespace std;

// two classes of objects

// Renderers - determine how an object is drawn
// Shapes - determine what to draw

struct Renderer
{
  virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer
{
  void render_circle(float x, float y, float radius) override
  {
    cout << "Rasterizing circle of radius " << radius << endl;
  }
};

struct RasterRenderer : Renderer
{
  void render_circle(float x, float y, float radius) override
  {
    cout << "Drawing a vector circle of radius " << radius << endl;
  }
};

