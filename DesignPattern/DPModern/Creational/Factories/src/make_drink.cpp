#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.h"
using namespace std;

unique_ptr<HotDrink> make_drink(string type)
{
  unique_ptr<HotDrink> drink;
  if (type == "tea")
  {
    drink = make_unique<Tea>();
    drink->prepare(200);
  }
  else 
  {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main()
{
  auto d = make_drink("tea");
  auto c = make_drink("coffee");

  getchar();
  return 0;
}
