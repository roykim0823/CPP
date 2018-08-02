#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

enum class Color { Red, Green, Blue };
enum class Size {Small, Medium, Large };

struct Product
{
  string name;
  Color color;
  Size size;
};

struct ProductFilter
{
  typedef vector<Product*> Items;
  static Items by_color(Items items, Color color)
  {
    Items result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  static Items by_size(Items items, Size size)
  {
    Items result;
    for (auto& i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

  // size and color
  static Items by_color_and_size(Items items, Size size, Color color)
  {
    Items result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }

  // violated OCP b/c we had to jump in and change the underlying object
  // stable objects are easier to maintain
};
