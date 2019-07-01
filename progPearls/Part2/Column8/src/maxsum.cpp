#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define N 1000000
int n;
float x[N];

template<typename T>
class maxSum {
protected:
	std::vector<T> x;
	
	T max(T a, T b) { return (a>b)? a : b; }

public:
	maxSum(int n=10): x(n) {}
	maxSum(std::vector<T> &a): x(a) {}
	~maxSum() {}

	void print() {
		for (int i=0; i<x.size(); i++)
			std::cout << x[i] << " ";
		std::cout << std::endl;
	}

	void fill() {	// sprinkle
		for (int i=0; i<x.size(); i++)
			x[i] = (1 - 2*( (float) rand()/RAND_MAX))*x.size();
	}

// O(n^3)
T maxSum1() {
	int i, j, k;
	T sum, maxsofar = 0;
	
	for(i=0; i<x.size(); i++) {
		for(j=i; j<x.size(); j++) {
			sum=0;
			for(k=i; k<=j; k++)	// sum is sum of x[i..j] 
				sum += x[k];
			maxsofar = max(maxsofar, sum);
		}
	}
	return maxsofar;
}

// O(n^2)
T maxSum2a() {
	int i, j, k;
	T sum, maxsofar = 0;
	
	for(i=0; i<x.size(); i++) {
		sum=0;
		for(j=i; j<x.size(); j++) {
			sum += x[j];	// sum is sum of x[i...j]
			maxsofar = max(maxsofar, sum);
		}
	}
	return maxsofar;
}

// O(n^2)
T maxSum2b() {
	int i, j, k;
	float sum, maxsofar = 0;
	std::vector<T> cumvec(x.size(), 0);	
	
	cumvec[0] = x[0];
	for(i=1; i<x.size(); i++) 
		cumvec[i] = cumvec[i-1] + x[i];	// precompute the cumulative sum
	
	for(i=0; i<x.size(); i++) {
		for(j=i; j<x.size(); j++) {
			sum = cumvec[j] - cumvec[i-1];	// sum is sum of x[i...j]
			maxsofar = max(maxsofar, sum);
		}
	}
	return maxsofar;
}

// O(nlogn)
T maxSum3R(int l, int u) {
	T lmax, rmax, sum;
	if(l > u) return 0;				// zero element
	if(l ==u) return max(0, x[l]);	// one element
	
	int i, m;
	m = (l+u)/2;

	// find max crossing to left
	lmax=sum=0;
	for(i=m; i>= l; i--) {
		sum += x[i];
		lmax = max(lmax, sum);
	}
	// find max crossing to right
	rmax=sum=0;
	for(i=m+1; i<= u; i++) {
		sum += x[i];
		rmax = max(rmax, sum);
	}
	return max(lmax + rmax, max( maxSum3R(l, m), maxSum3R(m+1, u)));
}

T maxSum3() { maxSum3R(0, x.size()-1); }

// O(n): scanning algorithm
T maxSum4a() {
	T maxsofar=0, maxendinghere=0;
	for(int i=0; i<x.size(); i++) {
		maxendinghere += x[i];
		if (maxendinghere < 0)
			maxendinghere=0;
		if (maxendinghere > maxsofar)
			maxsofar = maxendinghere;
	}
	return maxsofar;
}

// O(n)
T maxSum4b() {
	T maxsofar=0, maxendinghere=0;
	for(int i=0; i<x.size(); i++) {
		maxendinghere += x[i];
		maxendinghere = max(maxendinghere, 0);
		maxsofar = max(maxendinghere, maxsofar);
	}
	return maxsofar;
}
};

template<typename T>
void measure(maxSum<T> &t, int func) {
    int start=clock();
	T result;
	switch(func) {
		case 1:	result = t.maxSum1(); break;
		case 2:	result = t.maxSum2a(); break;
		case 3:	result = t.maxSum2b(); break;
		case 4:	result = t.maxSum3(); break;
		case 5:	result = t.maxSum4a(); break;
		case 6:	result = t.maxSum4b(); break;
		default: break;
	}
	int clicks = clock() - start;
	std::cout << func << " : " << result << " takes " << clicks << std::endl;
}
	

int main() {
	std::vector<int> x = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	maxSum<int> t(1000); t.fill();
//	maxSum<int> t(x);
//	t.print();
	for(int i=1; i<7; i++) 
		measure<int>(t, i); 
}

