// Broken Calls to Memory Allocation/Deallocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *mystr1=strdup("test"); 	// strdup returns a copy of its string argument.
	char *mystr2=strdup("TEST");    // strdup allocates the necessary memory on the heap
	mystr1=mystr2;                  // Two pointer points to "TEST"

	printf("mystr1 = %s\n", mystr1);
	free(mystr1);

	printf("mystr2 = %s\n", mystr2);	// mystr2 points to freed memory
	free(mystr2);

	return 0;
}
