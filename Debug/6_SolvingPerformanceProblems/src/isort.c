// isort.c
#include <stdio.h>
#include <stdlib.h>

typedef double Stype;

// Print an array of the given size on stdout
void print_array(const char* prefix, const Stype *array, int size) {
	int i;
	printf("%s:", prefix);
	for(i=0; i<size; i++)
		printf(" %f", array[i]);
	printf("\n"); fflush(stdout);
}

// swap 2 elements
void swap(Stype *a, int i, int j) {
	Stype tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

// check if 'a' is less than 'b'
int less(Stype a, Stype b) {
	return (a < b) ? 1 : 0;
}

// insert a[0] into pre-sorted array a[1]...a[n-1]
void insert_value(Stype *a, int n) {
	int i;
	for(i=1; i<n; i++) 
		if(less(a[i], a[i-1]))
			swap(a, i, i-1);
#ifdef ISORT_FAST	// compile with -DISORT_FAST to speed up
		else return;
#endif
}

// toplevel routine for isort
void isort(Stype *a, int n) {
	if(n <= 1)
		return;
	isort(a+1, n-1);
	insert_value(a, n);
}

/* partition array a, so that all values smaller than pivot a[n-1]
   are placed in a[0]...a[result-1], the pivot is in a [result],
   and the vlaues larger than the pivot are in a[result+1]...a[n-1]
*/
int partition(Stype *a, int n) {
	int i, result = 0;
	for(i = 0; i<n-1; i++)
		if(less(a[i], a[n-1])) {
			swap(a, result, i);
			result++;
		}
	swap(a, result, n-1);
#ifdef DEBUG
	print_array("partition", a, n);
	printf("pivot at: %d\n", result);
#endif
	return result;
}

// toplevel routine for quicksort
void quicksort(Stype *a, int n) {
	int i;
	if(n <= 1)
		return;
	i = partition(a, n);
	quicksort(a, i);
	quicksort(a+i+1, n-(i+1));
}

// program entry point
int main(int argc, char **argv) {
	const char *usage = "usage: isort i|q n iter, n>0, iter>0\n";
	int n, i, j, iterations, use_isort = 1;
	Stype *input, *result;

	if(argc != 4) {
		fprintf(stderr, usage);
		return 1;
	}

	if(argv[1][0] == 'q')
		use_isort = 0;
	
	n = atoi(argv[2]);
	iterations = atoi(argv[3]);
	if(n <= 0 || iterations <= 0) {
		fprintf(stderr, usage);
		return 2;
	}

	input = (Stype *) malloc(n * sizeof(Stype));
	result = (Stype *) malloc(n * sizeof(Stype));
	if(input == 0 || result == 0) {
		fprintf(stderr, "out of memory\n");
		return 3;
	}

	srand48(1); // always generate the same random sequence
	for(i=0; i<n; i++)
		input[i] = drand48();

	for(j=0; j<iterations; j++) {
		for(i=0; i<n; i++) 
			result[i] = input[i];
		if(use_isort)
			isort(result, n);
		else
			quicksort(result, n);
	}
#ifdef DEBUG
	print_array("input", input, n);
	print_array("result", result, n);
#endif
	free(input);
	free(result);
	return 0;
}
