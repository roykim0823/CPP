#include <assert.h>

class Rectangle {
public:
  virtual void setHeight(int newHeight) { h=newHeight; }
  virtual void setWidth(int newWidth)	{ w=newWidth; }
 
  virtual int height() const 	{ return h; }          // return current
  virtual int width() const 	{ return w; }           // values
private:
	int h;
	int w;
 };

class Square: public Rectangle { };
 
void makeBigger(Rectangle& r)          // function to
{                                      // increase r's area
  int oldHeight = r.height();
 
  r.setWidth(r.width() + 10);          // add 10 to r's width
 
  assert(r.height() == oldHeight);     // assert that r's
}                                      // height is unchanged
