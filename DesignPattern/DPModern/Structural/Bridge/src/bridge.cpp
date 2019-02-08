#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Shape.h"
using namespace std;

// two classes of objects

// Renderers - determine how an object is drawn
// Shapes - determine what to draw

void renderers()
{
  // Use Raster Renderer
  RasterRenderer rr;
  Circle raster_circle{ rr, 5,5,5 };
  raster_circle.draw();
  raster_circle.resize(2);
  raster_circle.draw();

  // Use Vector Renderer
  VectorRenderer vr;
  Circle raster_circle2{ vr, 4, 4, 4};
  raster_circle2.draw();
  raster_circle2.resize(4);
  raster_circle2.draw();
}

int main()
{
  
  cout << "Person Bridge..." << endl;
  Person p;
  p.greet();
  cout << endl;

  cout << "Render Bridge..." << endl;
  renderers();
  return 0;
}
