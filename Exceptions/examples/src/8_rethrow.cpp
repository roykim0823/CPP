#include <iostream>
using namespace std;

/* In C++, try-catch blocks can be nested. Also, an exception can be re-thrown
   using “throw; ”
*/
int main()
{
	try {
		try {
			throw 20;
		}
		catch (int n) {
			cout << "Handle Partially " << endl;
			throw; //Re-throwing an exception
		}
	}
	catch (int n) {
		cout << "Handle remaining " << endl;
	}
	return 0;
}
