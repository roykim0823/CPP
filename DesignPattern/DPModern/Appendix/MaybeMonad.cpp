#include <iostream>
#include <memory>
#include <string>
#include <stdio.h>
#include <functional>
//#include <boost/optional.hpp>

using namespace std;

struct Address {
  string* house_name = nullptr;
};

struct Person {
  Address* address = nullptr;
};

template <typename T> struct Maybe;

// a helper global function to deduce the template argument
template <typename T> Maybe<T> maybe(T* context)
{
  return Maybe<T>(context);
}

// define a new type Maybe<T> that is used as a temporary object that 
// participates in the drilling-down process
template <typename T> 
struct Maybe {
  T* context;

  Maybe(T *context) : context(context) { }

  // "drilling down" is encapsulated into a template parameter TFunc
  // This is "higher-order" function that takes a function
  template <typename TFunc>
  auto With(TFunc evaluator)
  {
	// Conventional C++
    /*if (context == nullptr)
      return Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
    return maybe(evaluator(context));*/

   	// This function takes another fuction called "evaluator" which,
	// given that the current context is non-null, can be called on a context
	// and return a pointer that can be wrapped in another Maybe.
	// This trick allows the chaining of With() calls
    return context != nullptr ? maybe(evaluator(context)) : nullptr;
  };

  // Do function simply invoking the given function on the context without changing
  // the context itself.
  template <typename TFunc>
  auto Do(TFunc action)
  {
    if (context != nullptr) action(context);
    return *this;
  }
};

void print_house_name(Person* p)
{
  //    if (p != nullptr && p->address != nullptr && p->address->house_name != nullptr)
  //        cout << *p->address->house_name << endl;
  auto z = maybe(p)
    .With([](auto x) { return x->address; })
    .With([](auto x) { return x->house_name; })
    .Do([](auto x) { cout << *x << endl; });
}

int main()
{
  print_house_name(nullptr);

  Person p;
  print_house_name(&p);	// nothing

  p.address = new Address;
  p.address->house_name = new string("My Big Castle");
  print_house_name(&p);	

  delete p.address->house_name;
  delete p.address;

  return 0;
}
