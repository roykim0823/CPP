#include <iostream>
using namespace std;

class B {
public:
  // B::mf is nonvirtual (so statically bound).
  // Also notice the difference if you *do* make this function virtual!
  void mf() { cout << "B::mf()" << endl; }
};

class D: public B {
public:
  // D::mf is nonvirtual (so statically bound).
  // Notice the difference in behavior when D has defined its own version
  // of mf!!!
  void mf() { cout << "D::mf()" << endl; }  // hides B::mf; see Item 50
};

// Using final and override to avoid the redefine non-virtual

class B2 {
public:
	virtual void mf() final { cout <<"B2::mf()" << endl; }
	virtual void mf2()  { cout <<"B2::mf2()" << endl; }
};

class D2: public B2 {
public:
	// virtual void mf() { cout << "D2:mf()" << endl; };   	// compilation error
	virtual void mf2() override final { cout << "D2::mf2()" << endl; };     
};

int main()
{

  D x;                          // x is an object of type D

  // Using pointer to Base.
  B *pB = &x;                   // get pointer to x

  pB->mf();                     // call B::mf through pointer

  // Using pointer to Derived.
  D *pD = &x;                   // get pointer to x

  pD->mf();                     // call D::mf through pointer

  D2 y;
  B2 *pB2 = &y;
  pB2->mf();
  pB2->mf2();

  D2 *pD2 = &y;
  pD2->mf();
  pD2->mf2();

}
