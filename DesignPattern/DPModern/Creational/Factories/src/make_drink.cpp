#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.h"
#include "FunctionalFactory.h"
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

int main() {
  auto d = make_drink("tea");
  auto c = make_drink("coffee");

  // Functional Factory
  DrinkWithVolumeFactory dvf;
  auto coffee = dvf.make_drink("coffee");
  auto tea = dvf.make_drink("tea");
  getchar();
  return 0;
}
