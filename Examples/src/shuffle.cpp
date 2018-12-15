// Implement Perfect Shuffle assuming having a perfect random generator
// When a randon number is picked, then swapped it to the current index
	/*
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;
	for(int i=0; i<10; i++)
		cout << u(e) << endl;
	*/

#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

void Swap(int &a, int &b){	
    int t = a;
    a = b;
    b = t;
}

// Similar to Knuth shuffle
void RandomShuffle(int a[], int n){
    for(int i=0; i<n; ++i){
        int j = rand() % (n-i) + i;	// Generate Random index 	
        Swap(a[i], a[j]);           // Swap it to the increasing index
    }
}

// Naive shffule
void NaiveShuffle(int a[], int n) {
	// Store all the index of the array into a set
	set<int> remaining;
	for(int i=0; i<n; i++)
		remaining.insert(i);
	
	unsigned cnt=0;
	// Use random value to print the array elements randomly
	int i=0;
	while(!remaining.empty()) {
		cnt++;
		int index=rand()%n;
		if(remaining.find(index)!=remaining.end()) {
			//cout << A[index] << endl;
			swap(a[i++], a[index]);
			remaining.erase(index);
		}
	}
}

void print(int a[], int n) {
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
    srand((unsigned)time(0));
    int n = 10;
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    int b[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    RandomShuffle(a, n);
	print(a, n);
	
    NaiveShuffle(b, n);
	print(b, n);
    return 0;
}
