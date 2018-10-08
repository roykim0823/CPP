#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.h"
#include "DrinkFactory.h"
using namespace std;

int main()
{
  DrinkFactory df;
  df.make_drink("coffee");

  getchar();
  return 0;
}
