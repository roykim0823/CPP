#include "virtual_proxy.h"

int main()
{
  LazyBitmap img{ "pokemon.png" };
  draw_image(img); // loaded whether the bitmap is loaded or not
  return 0;
}
