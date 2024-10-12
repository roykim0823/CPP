// open closed principle
// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product
{
  string name;
  Color color;
  Size size;
};

struct ProductFilter
{
  typedef vector<Product*> Items;

  Items by_color(Items items, const Color color)
  {
    Items result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

	// outright duplication
  Items by_size(Items items, const Size size)
  {
    Items result;
    for (auto& i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

	// outright duplication, what if there is another condition to add? -> not scalable
  Items by_size_and_color(Items items, const Size size, const Color color)
  {
    Items result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }
};

int main()
{
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  const vector<Product*> items { &apple, &tree, &house };

  ProductFilter pf;
  auto green_things = pf.by_color(items, Color::Green);
  for (auto& item: green_things) {
    cout << item->name << " is green.\n";
  }
  
  return 0;
}
