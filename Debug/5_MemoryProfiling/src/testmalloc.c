// testmalloc.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _MSC_VER
#define sleep(x)	_sleep(1000*(x))
#endif

#define blocksize 1024

// make the program wait, to inspect precess for memory use
void wait_for_input(const char *prefix, int is_interactive) {
	char c;
	if(is_interactive) {
		printf("%s hit return to continue\n", prefix); fflush(stdout);
		c = getchar();
	}
	else
	{
		sleep(1);
	}
}

// program entry point
int main(int argc, char **argv) {
	const char *usage = "usage: testmalloc i[interactive]|n n iter\n";
	int n, i, j, iterations, is_interactive = 0;
	int **myarray;

	if(argc != 4) {
		fprintf(stderr, usage);
		return 1;
	}

	if(argv[1][0] == 'i')
		is_interactive = 1;
	
	n = atoi(argv[2]);
	iterations = atoi(argv[3]);
	if( n <= 0 | iterations < 0 ) {
		fprintf(stderr, usage);
		return 2;
	}

	for(i=0; i<iterations; i++) {
		wait_for_input("before malloc: ", is_interactive);
#ifdef USE_NEW
		myarray = new int*[n];
#else
		myarray = (int **)malloc(n*(sizeof(int*)));
#endif
		for(j=0; j<n; j++) {
#ifdef USE_NEW
		myarray[j] = new int[blocksize];
#else
		myarray[j] = (int *)malloc(blocksize*(sizeof(int)));
#endif
		}
		wait_for_input("after malloc: ", is_interactive);
		for(j=0; j<n; j++) {
#ifdef USE_NEW
		delete[] myarray[j];;
#else
		free(myarray[j]);
#endif
		}
#ifdef USE_NEW
		delete[] myarray;;
#else
		free(myarray);
#endif
	}
	return 0;
}
