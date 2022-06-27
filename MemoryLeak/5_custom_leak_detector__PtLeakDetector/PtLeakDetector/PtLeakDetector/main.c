#include "ptmain.h"
#include <string.h>

int main() {
	int *p = malloc(sizeof(int)) ;
	char *p2 = malloc(6) ;
	strcpy(p2, "Hello") ;
	//free(p) ;
	PtDumpLeaks() ;
}
