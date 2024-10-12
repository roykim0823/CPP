// Objects in a program should be replaceable with instances of their subtypes/drieved types
// w/o altering the correctness of the program

#include <iostream>

class Rectangle {
protected:
  int width, height;
  Rectangle(const int width, const int height)
    : width{width}, height{height} { }

public:
  static Rectangle create_rectangle(int w, int h) {
    return {w, h};
  }
  static Rectangle create_square(int size) {
    return {size, size};
  }

  int get_width() const { return width; }

  int get_height() const { return height; }

  int area() const { return width * height; }
};


void process(Rectangle& r)
{
  // no set_* functions for the simplicity
  int w = r.get_width();
  int h = r.get_height();
  std::cout << "expected area = " << (w * h) 
    << ", got " << r.area() << std::endl;
}

int main()
{
  Rectangle r = Rectangle::create_rectangle(3, 4);
  process(r);

  Rectangle s = Rectangle::create_square(5);
  process(s);

  return 0;
}
