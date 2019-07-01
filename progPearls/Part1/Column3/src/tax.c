#include <stdio.h>

// Hardcoded -> Use array of a structure
struct tax_descriptor {
	unsigned long long income;
	unsigned long long base;
	float increment;
};

// The array must be guarded with an initial 0-income entry, 
// so that a general rule can be applied even for boundary condition cases like income <= 2200.
// For the same reason, the end of the array must be guarded with an infinity value that 
// applies the largest tax.
struct tax_descriptor taxes[] = {
	{ 0ULL, 	0ULL, 		0.0f }, 
	{ 2200ULL, 	0ULL, 		0.0f },
	{ 2700ULL, 	0ULL, 		0.14f },
	{ 3200ULL, 	70ULL, 		0.15f },
	{ 3700ULL, 	145ULL, 	0.16f },
	{ 4200ULL, 	225ULL, 	0.17f },
	{ 0ULL, 	53090ULL, 	0.70f }
};

int get_position(unsigned long long income) {
	int taxListSize = (int) sizeof(taxes)/sizeof(taxes[0]) - 1;
	int i;
	for (i = 0; i < taxListSize && income > taxes[i].income; i++);
	return i;
}

long double calculate_tax(unsigned long long income) {
	int pos = get_position(income);
	struct tax_descriptor tax = taxes[pos];
	return tax.base + (long double) tax.increment*(income - taxes[pos-1].income);
}

// NOTE: Even though I used wide enough types to represent numbers, 
// in a real-world implementation, and given the importance of this matter, 
// it would be wise to use errno.h and test for overflow conversions 
// after calling scanf() and printf().
int main(int argc, char *argv[]) {
	int i;
	unsigned long long income;
	for (i = 1; i < argc; i++) {
		sscanf(argv[i], "%llu", &income);
		printf("%llu\t%.2Lf\n", income, calculate_tax(income));
	}
	return 0;
}
