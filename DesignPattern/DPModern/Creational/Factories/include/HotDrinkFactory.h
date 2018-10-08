#pragma once
#include "HotDrink.h"

// Abstract Factory
struct HotDrinkFactory
{
  virtual unique_ptr<HotDrink> make() const = 0;
};
