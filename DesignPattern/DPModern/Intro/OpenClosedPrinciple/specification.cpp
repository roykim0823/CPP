#include "product.h"

template <typename T> struct AndSpecification;

template <typename T> struct Specification
{
  virtual bool is_satisfied(T* item) = 0;

  // Use && -> process of filtering by two (or more!)
  AndSpecification<T> operator&&(Specification& other) 
  {
	  return AndSpecification<T>(*this, other);
  }

};

template <typename T> struct Filter
{
  virtual vector<T*> filter(
  	vector<T*> items, 
	Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
  vector<Product*> filter(
  	vector<Product*> items, 
	Specification<Product>& spec) override
  {
    vector<Product*> result;
    for (auto& p : items)
      if (spec.is_satisfied(p))
        result.push_back(p);
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;

  explicit ColorSpecification(const Color color)
    : color{color}
  {
  }


  bool is_satisfied(Product* item) override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product>
{
  Size size;

  explicit SizeSpecification(const Size size)
    : size{ size }
  {
  }

  bool is_satisfied(Product* item) override {
    return item->size == size;
  }
};

template <typename T> struct AndSpecification : Specification<T>
{
  Specification<T>& first;
  Specification<T>& second;

  AndSpecification(Specification<T>& first, Specification<T>& second)
    : first{first},
      second{second}
  {
  }

  bool is_satisfied(T* item) override
  {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main()
{
  Product apple{ "Apple", Color::Green, Size::Small };
  Product tree{ "Tree", Color::Green, Size::Large };
  Product house{ "House", Color::Blue, Size::Large };

  vector<Product*> all{ &apple, &tree, &house };

  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green" << endl;

  SizeSpecification big(Size::Large);
  AndSpecification<Product> green_and_big{ big, green };

  auto big_green_things = bf.filter(all, green_and_big);
  for (auto& x : big_green_things)
    cout << x->name << " is big and green" << endl;

  //auto green_and_big2 = ColorSpecification(Color::Green) 
  //					   && SizeSpecification(Size::Large);
  auto green_and_big2 = green && big;
  
  auto big_green_things2 = bf.filter(all, green_and_big2);
  for (auto& x : big_green_things2)
    cout << x->name << " is big and green 2" << endl;

  getchar();
  return 0;
}
