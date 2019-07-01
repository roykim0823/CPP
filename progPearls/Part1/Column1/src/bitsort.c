// 	bitsort.c -- bitmap sort from Column 1
// 	Sort distinct integers in the range [0..N-1]

#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F		// 0x0001FFFF = 31 
#define N 10000000

int a[N/BITSPERWORD + 1];

// i & MASK = the bit postion in the 32 bits 
void set(int i) { 			a[i>>SHIFT] |= 	(1 << (i & MASK)); }
void clr(int i) { 			a[i>>SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) { return 	a[i>>SHIFT] &	(1 << (i & MASK)); }

int main() {
	int i;

	// phase 1: initialize set to empty 
	//for(i=0; i<N; i++)  	// clear each bit -> inefficient
	//	clr(i);

	int top = N/BITSPERWORD + 1;
	for(i=0; i<top; i++) 
		a[i] = 0;

	// phase 2: insert present elements into the set
	while(scanf("%d", &i) != EOF)
		set(i);
	
	// phase 3: write sorted output
	for(i=0; i<N; i++)  {
		if(test(i))
			printf("%d\n", i);
	}
	
	return 0;
}
