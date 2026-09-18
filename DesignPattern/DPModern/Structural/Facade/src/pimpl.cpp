#include <iostream>
#include "Console.h"
#include "Person.h"

using namespace std;

// Is pimpl a facade? They rhyme - both put a narrow interface in front of
// something messier - but they solve different problems. Run this and compare.
int main()
{
  cout << "--- pimpl: one class hiding its own implementation ---\n";
  Person p{"Roy"};
  p.greet();
  p.remember("pimpl is a compilation firewall");
  p.remember("Facade is about API surface, not build times");
  p.greet();

  Person moved = std::move(p);      // the handle moves; the Impl never does
  moved.greet();

  // The client's view of Person is one pointer, whatever Impl grows into.
  cout << "sizeof(Person)  = " << sizeof(Person) << " bytes (just the pointer)\n";
  cout << "sizeof(Console) = " << sizeof(Console)
       << " bytes (a facade is a normal object; it hides nothing from the compiler)\n";

  cout << "\n--- the difference in one line each ---\n";
  cout << "Facade : many classes -> one convenient interface   (for the caller's sanity)\n";
  cout << "pimpl  : one class    -> one opaque pointer         (for the compiler/linker)\n";
  return 0;
}
