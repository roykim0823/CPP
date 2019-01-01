#include "crtp2_staticInterface.h"

int main() {
	Constant42 c42;
	print(c42);
	Variable v(43);
	print(v);
	return 0;
}
