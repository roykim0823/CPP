#include <stdio.h>
#include <limits.h>
#include <errno.h>

#define N 10000000
#define CHAR_BIT_LOG 3 /* assumes that CHAR_BIT == 8, so log_2(8) = 3 */
#define MASK (~(~0 << CHAR_BIT_LOG))
#define setbit(a, x) 	((a)[(x) >> CHAR_BIT_LOG] |= 1 << ((x) & MASK))
#define isset(a, x) 	((a)[(x) >> CHAR_BIT_LOG] & (1 << ((x) & MASK)))

char arr[(N-1)/CHAR_BIT+1];

int main() {
	int n;
	
	/* Read and store every number */
	errno = 0;
	while (scanf("%d", &n) == 1 || errno == ERANGE) { // scanf return 0 if an input is not numeric
		if (errno == ERANGE)		// handle the range error
			fprintf(stderr, "Warning: integer conversion overflow, skipping.\n");
		else if (n < 0 || n >= N)	// handle input <0 or input >= n
			fprintf(stderr, "Warning: out-of-range number: %d\n", n);
		else if (isset(arr, n))   	// handle a duplicate input
			fprintf(stderr, "Warning: duplicate entry: %d\n", n);
		else
			setbit(arr, n);
		errno = 0;
	}
	
	if (!feof(stdin)) {	// check EOF comes from stdin
		fprintf(stderr, "Warning: invalid input detected. Aborting.\n");
		return 1;
	}
	
	/* Print sorted result */
	for (n = 0; n < N; n++)
		if (isset(arr, n))
			printf("%d\n", n);
	
	return 0;
}
