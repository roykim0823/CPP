#include <iostream>
using namespace std;

/* Unlike Java, in C++, all exceptions are unchecked. Compiler doesn’t
   check whether an exception is caught or not (See this for details).
  For example, in C++, it is not necessary to specify all uncaught exceptions
  in a function declaration. Although it’s a recommended practice to do so.
  For example, the following program compiles fine, but ideally signature of
  fun() should list unchecked exceptions.
*/

// This function signature is fine by the compiler, but not recommended.
// Ideally, the function should specify all uncaught exceptions and function
// signature should be "void fun(int *ptr, int x) throw (int *, int)"
void fun(int *ptr, int x)
{
	if (ptr == NULL)
		throw ptr;
	if (x == 0)
		throw x;
	/* Some functionality */
}

int main()
{
	try {
	fun(NULL, 0);
	}
	catch(...) {
		cout << "Caught exception from fun()" << endl;
	}
	return 0;
}
