#include <iostream>
using namespace std;

int main()
{
  int x, y, z;

  x=1; y=2; z=3;

  // assignment returns a reference to its left-hand argument
  x = y = z = 14;
  cout << x << " " << y << " " << z << endl;
  // assignment is right-associative, the above assignment chain is parsed like:
  x = (y = ( z = 15));  // legal!  assigns i2 to i1, then i3 to i1!
  cout << x << " " << y << " " << z << endl;

}
