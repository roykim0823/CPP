#include <string>
#include <iostream>
using namespace std;

class Shape {

public:
  // pure virtual func: inherit a function iterface "only" 
  virtual void draw() const = 0; 		
  
  // simple virtual func: inherit a function iterface and a default implementation 
  virtual void error(const string& msg);

  // non-virtual function: inherit a function iterfact and a "mandatory" implementation
  int objectID() const;
};

void Shape::draw() const
{
  cout << "Shape::draw()" << endl;
}

void Shape::error(const string& msg)
{
  cout << msg << endl;
}

int Shape::objectID() const
{
  return 1;
}

class Rectangle: public Shape {
public:
  void draw() const { cout << "Rectangle::draw()" << endl; }
};

class Ellipse: public Shape {
public:
  void draw() const { cout << "Ellipse::draw()" << endl; }
};


int main()
{
  //Shape *ps = new Shape;         // error! Shape is abstract
  
  Shape *ps1 = new Rectangle;      // fine
  ps1->draw();                     // calls Rectangle::draw
  
  Shape *ps2 = new Ellipse;        // fine
  ps2->draw();                     // calls Ellipse::draw
  
  ps1->Shape::draw();              // calls Shape::draw
  ps2->Shape::draw();              // calls Shape::draw
}
