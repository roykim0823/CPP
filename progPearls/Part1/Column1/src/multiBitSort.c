#include <stdio.h>
#include <limits.h>

#define N 10000000
#define INTBITS 4 	/* says how many bits each number uses */
#define MASK 0x0F
#define incr(a, x) 		((a)[(x)/(CHAR_BIT/INTBITS)] += 1 << ((x)%(CHAR_BIT/INTBITS))*INTBITS)
#define getcnt(a, x)   (((a)[(x)/(CHAR_BIT/INTBITS)] >> (((x)%(CHAR_BIT/INTBITS))*INTBITS)) & MASK)

unsigned char arr[(N*INTBITS-1)/CHAR_BIT+1];

int main() {
	int n;
	unsigned char c;
	
	/* Read and store every number */
	while (scanf("%d", &n) == 1)
		incr(arr, n);
	
	/* Print sorted result */
	for (n = 0; n < N; n++)
		for (c = getcnt(arr, n); c > 0; c--)
			printf("%d\n", n);
	
	return 0;
}
