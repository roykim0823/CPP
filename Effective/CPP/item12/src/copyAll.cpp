class Base {
public:
  Base(int initialValue = 0): x(initialValue) {}  // default constructor
  Base(const Base& rhs): x(rhs.x) {}              // copy constructor
  Base& operator=(const Base &rhs) {             // copy assignment operator
    x = rhs.x;
    return *this;
  }

private:
  int x;
};


class Derived: public Base {
public:
  Derived(int initialValue = 0)
  : Base(initialValue), y(initialValue) {}

  //Derived(const Derived& rhs)      // erroneous copy
  //: y(rhs.y) {}                    // constructor

  Derived(const Derived& rhs)        // correct copy
  : Base(rhs), y(rhs.y) {}           // constructor

  Derived& operator=(const Derived& rhs); // copy assignment operator
private:
  int y;
};

// ERRONEOUS assignment operator: the data member x in the Base part of a
// Derived object is unaffected by this assignment operator.
//Derived& Derived::operator=(const Derived& rhs)
//{
//  if (this == &rhs) return *this;    // see Item 17
//
//  y = rhs.y;                         // assign to only Derived's
//
//  return *this;                      // see Item 15
//}

// CORRECT assignment operator.
Derived& Derived::operator=(const Derived& rhs)
{
  if (this == &rhs) return *this;

  Base::operator=(rhs);    // call this->Base::operator=
  y = rhs.y;

  return *this;
}

int main() {
  Derived d1(3);    // d1.x = 3, d1.y = 3
  Derived d2 = d1;  // call copy constructors
  Derived d3;
  d3 = d1;
}
