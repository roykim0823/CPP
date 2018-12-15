#include <iostream>
using namespace std;

/* Stack Unwinding
   The process of remving function entries from function call stack at run time.
   When an exception occurs, the function call tack is linearly searched for
   the exception handler, and all the entries before the function with exception
   handler are removed from the fuction call stack.
   SStack Unwinding if exception is not handled in the same function (where it thrown)
*/

void f1() throw (int) {
  cout << "f1() starts" << endl;
  throw 100;
  cout << "f1() ends" << endl;
}

void f2() throw (int) {
  cout << "f2() starts" << endl;
  f1();
  cout << "f2() ends" << endl;
}

void f3() {
  cout << "f3() starts" << endl;
  try {
    f2();
  }
  catch (int i) {
    cout << "Caught Exception: " << i << endl;
  }
  cout << "f3() ends" << endl;
}

/* when f1() throws exception, its entry is removed from the function call Stack
   because f1() doesn't contain exception handler for the thrown exception.
   Then, next entry in call stack is looked for exception handler.
   Since f2() also doesn't have handler, its entry is also removed from function
   call stack. The next entry f3() contains exception handler, the catch block
   inside f3() is executed
*/
int main() {
  f3();

  getchar();
  return 0;
}
