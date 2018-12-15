#include <iostream>
using namespace std;

/* implicit type conversion doesn’t happen for primitive types. For example,
   in the following program ‘a’ is not implicitly converted to int
*/
int main()
{
	try {
	throw 'a';
	}
	catch (int x) {
		cout << "Caught " << x;
	}
	catch (...) {
		cout << "Default Exception\n";
	}
	return 0;
}
