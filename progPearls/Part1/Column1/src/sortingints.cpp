// 	sortints.cpp -- Sort input set of integers using STL set 
// 	Sort distinct integers in the range [0..N-1]

#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> S;	// ordered set
	int i;

	while(cin >> i)
		S.insert(i);

	set<int>::iterator iter;
	for(iter=S.begin(); iter!=S.end(); ++iter) 
		cout << *iter << "\n";
	
	return 0;
}
