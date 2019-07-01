/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */
#include "util.h"
#include "intSet.h"
#include "intSetList.h"
#include "intSetBST.h"
#include "intSetBitVec.h"
#include "intSetBin.h"

// P13.1
void genfloyd(int m, int maxval)
{
	int *v = new int[m];
	IntSetSTL S(m, maxval);
	for (int j = maxval-m; j < maxval; j++) {
		int t = bigrand() % (j+1);
		int oldsize = S.size();
		S.insert(t);
		if (S.size() == oldsize) // t already in S
			S.insert(j);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << "\n";
}

int main(int argc, char *argv[])
{
	if(argc<3) {
		cout << "usage: ./intSet n maxvalu" << endl;
		return 0;
	}
	int m = atoi(argv[1]);
	int maxval = atoi(argv[2]);
	
	cout << "IntSetSTL( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetSTL>(m, maxval);
	cout << "IntSetArr( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetArr>(m, maxval);
	cout << "IntSetList( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetList>(m, maxval);
	cout << "IntSetBST( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetBST>(m, maxval);
	cout << "IntSetBitVec( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetBitVec>(m, maxval);
	cout << "IntSetBin( " << m << ", " << maxval << " ) " << endl;
	gensets<IntSetBin>(m, maxval);
	cout << "1. genfloyd( " << m << ", " << maxval << " ) " << endl;
	genfloyd(m, maxval);
	//gensets<IntSetBin>(m, maxval);
	// overheadonly(m, n);
	// memaccesstest(m, n);

	return 0;
}
