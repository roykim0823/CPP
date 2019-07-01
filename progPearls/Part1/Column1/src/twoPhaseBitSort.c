#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

// Limitation: 1MB memory, bitvector for 10 million =1.25MB
// solution 2 pass algorithm
// * A k-pass algorithm sorts at most n nonrepeated positive integers less than in in time kn and space n/k.

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F		// 0x0001FFFF = 31 
#define N 10000000
//#define N 100

#define ARR_SIZE 	(N/BITSPERWORD+1)/2+1
int a[ARR_SIZE];

// i & MASK = the bit postion in the 32 bits 
void set(int i) { 			a[i>>SHIFT] |= 	(1 << (i & MASK)); }
void clr(int i) { 			a[i>>SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) { return 	a[i>>SHIFT] &	(1 << (i & MASK)); }

void readnumbers(int, int, FILE *);
void printnumbers(int, int);
void clearA();

int main(int argc, char *argv[]) {
	FILE *f;
	
	if (argc != 2) {
		fprintf(stderr, "[%s] Usage: %s input-file\n", argv[0], argv[0]);
		return 1;
	}
	
	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "[%s] Could not open file %s\n", argv[0], argv[1]);
		return 1;
	}
	
	/* 1st pass, sort from 0 to N/2-1 */
	clearA();	// init the bit vector
	readnumbers(0, N/2-1, f);
	printnumbers(0, N/2);
	
	rewind(f);
	
	/* 2nd pass, sort from N/2 to N */
	clearA();	// init the bit vector
	readnumbers(N/2, N-1, f);
	printnumbers(N/2, N/2);
	
	fclose(f);

	return 0;
}

void readnumbers(int from, int to, FILE *fp) {
	int num;
	while (fscanf(fp, "%d", &num) == 1) {
		if (num >= from && num <= to)
			set(num - from); 	// num - from : compensate the correct index
	}
}

void printnumbers(int from, int size) {
	int i;
	for(i=0; i<size; i++)
		if (test(i))
			printf("%d\n", i+from);	// num + from : compensate the correct output
}

void clearA() {
	int i;
	for(i=0; i<ARR_SIZE; i++)
		a[i]=0;
}
