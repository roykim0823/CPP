/*
 * main.cpp
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "ArrayStack.h"
#include "FastArrayStack.h"
#include "ArrayDeque.h"
#include "DualArrayDeque.h"
#include "RootishArrayStack.h"

using namespace ods;

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000
#endif

const unsigned RA=0x0001;   // random access
const unsigned FM=0x0002;   // front modifications

template <class List>
void listTests(List &ell, int n, unsigned flags)
{
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(5);

	ell.clear();

	clock_t start, stop;
	cout << "Adding " << n << " elements...";
	cout.flush();
	start = clock();
	for (int i = 0; i < n; i++)
		ell.add(ell.size(), i);
	stop = clock();
	cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

	if (flags & RA) {
		cout << "Reading " << n << " elements...";
		cout.flush();
		start = clock();
		for (int i = 0; i < n; i++)
			assert(ell.get(i) == i);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

		cout << "Setting " << n << " elements...";
		cout.flush();
		start = clock();
		for (int i = 0; i < n; i++)
			ell.set(i, 2*i);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;
	} else {
		cout << "Reading 2log(" << n << ") elements...";
		cout.flush();
		start = clock();
		for (int i = 1; i < n; i*=2) {
			assert(ell.get(i) == i);
			assert(ell.get(n-i-1) == n-i-1);
		}
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

		cout << "Setting 2log(" << n << ") elements...";
		cout.flush();
		start = clock();
		for (int i = 1; i < n; i*=2) {
			ell.set(i, 2*i);
			ell.set(n-i-1, 2*(n-i-1));
		}
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

	}

	if (flags & FM) {
		cout << "Adding " << n << " elements at front...";
		cout.flush();
		start = clock();
		for (int i = 0; i < n; i++)
			ell.add(0, i);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

		cout << "Removing " << n << " elements at front...";
		cout.flush();
		start = clock();
		for (int i = 0; i < n; i++)
			ell.remove(0);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;
	} else {
		cout << "Adding log(" << n << ") elements at front...";
		cout.flush();
		start = clock();
		for (int i = 1; i < n; i*=2)
			ell.add(0, i);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;

		cout << "Removing log(" << n << ") elements at front...";
		cout.flush();
		start = clock();
		for (int i = 1; i < n; i*=2)
			ell.remove(0);
		stop = clock();
		cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;
	}

	cout << "Removing " << n << " elements...";
	cout.flush();
	start = clock();
	for (int i = 0; i < n; i++)
		ell.remove(ell.size()-1);
	stop = clock();
	cout << "done (" << ((double)(stop-start))/CLOCKS_PER_SEC << "s)" << endl;
}


int main(int argc, char **argv)
{
	int n = 1000000;

	srand(0);

	cout << endl << "ArrayStack<int>:" << endl;
	ArrayStack<int> as;
	listTests(as, n, RA);


	cout << endl << "FastArrayStack<int>:" << endl;
	FastArrayStack<int> fas;
	listTests(fas, n, RA);

	cout << endl << "ArrayDeque<int>:" << endl;
	ArrayDeque<int> ad;
	listTests(ad, n, RA|FM);

	cout << endl << "DualArrayDeque<int>:" << endl;
	DualArrayDeque<int> dad;
	listTests(dad, n, RA|FM);

	cout << endl << "RootishArrayStack<int>:" << endl;
	RootishArrayStack<int> ras;
	listTests(ras, n, RA);

	return 0;
}

