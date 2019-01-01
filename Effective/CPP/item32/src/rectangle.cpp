#include <assert.h>
#include "rectangle.h"

int main()
{
  Square s;
  
  assert(s.width() == s.height());      // this must be true
                                        // for all squares
   
  makeBigger(s);                        // by inheritance, s
                                        // isa Rectangle, so
                                        // we can increase its
                                        // area
  
  assert(s.width() == s.height());      // this must still be
                                        // true for all squares
}
