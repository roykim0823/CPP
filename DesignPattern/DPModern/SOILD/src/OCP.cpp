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


template <typename T> struct AndSpecification;

// the definition of a predicate to apply to a data element
template <typename T> struct Specification
{
  virtual bool is_satisfied(T* item) = 0;

  // new: breaks OCP if you add it post-hoc
  // Use && -> process of filtering by two (or more!)
  //AndSpecification<T> operator&&(Specification<T>&& other)
  AndSpecification<T> operator&&(Specification<T>& other)  // to support &&
  {
    return AndSpecification<T>(*this, other);
  }
};

template <typename T> AndSpecification<T> operator&&
  (Specification<T>&& first, Specification<T>&& second)
{
  return { first, second };
}


template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items,
                            Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{  
  vector<Product*> filter(vector<Product*> items,
                           Specification<Product> &spec) override
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

  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) override {
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

  AndSpecification(Specification<T> &first, Specification<T> &second) 
    : first(first), second(second) {}

  bool is_satisfied(T *item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};


int main()
{
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  const vector<Product*> all { &apple, &tree, &house };

  BetterFilter bf;
  ColorSpecification green(Color::Green);
  
  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green\n";

  SizeSpecification large(Size::Large);
  AndSpecification<Product> green_and_large(green, large);
  auto big_green_things = bf.filter(all, green_and_large);
  for (auto& x : big_green_things)
    cout << x->name << " is big and green\n";

  //auto spec = ColorSpecification{Color::Green} &&  	// Seg Fault 
  //            SizeSpecification{Size::Large};
  auto green_and_large2 = green && large;
  auto green_large = bf.filter(all, green_and_large2);
  for (auto& x : green_large)
  //for(auto &x : bf.filter(all, spec))
    cout << x->name << " is green and large\n";

  return 0;
}
