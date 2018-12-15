#include <iostream>
using namespace std;

/* There is a special catch block called ‘catch all’ catch(…) that can be
   used to catch all types of exceptions. For example, in the following program,
	 an int is thrown as an exception, but there is no catch block for int,
	 so catch(…) block will be executed.
*/
int main()
{
	try {
	throw 10;
	}
	catch (char *excp) {
		cout << "Caught " << excp;
	}
	catch (...) {
		cout << "Default Exception\n";
	}
	return 0;
}
