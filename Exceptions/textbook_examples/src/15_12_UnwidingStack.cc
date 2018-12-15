// unwiding the stack
#include <iostream>
#include <cmath>
#include <cstring>
#include "exe_mean.h"

class Demo {
private:
	char word[40];
public:
	Demo(const char *str) {
		std::strcpy(word, str);
		std::cout << "Demo " << word << " created\n";
	}

	~Demo() {
		std::cout << "Demo " << word << " destroyed\n";
	}

	void show() const {
		std::cout << "Demo " << word << " lives.\n";
	}

};

// fuction prototype
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
//double means(double a, double b);// throw(bad_hmean, bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	Demo d1("found in main()");
	cout << "Enter two numbers: ";
	while(cin >> x >> y) {
		try {
			z=means(x, y);
			cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
			cout << "Enter next pair: ";
		}
		catch (bad_hmean &bg) {
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean &hg) {
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "Sorry, you don't ge to play any more." << endl;
			break;
		}
	}
	d1.show();
	cout << "Bye!" << endl;
	return 0;
}

double hmean(double a, double b) throw(bad_hmean) 
{
	if (a==-b) 
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a+b);
}

double gmean(double a, double b) throw(bad_gmean) 
{
	if (a < 0 || b <0) 
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}

//double means(double a, double b) { // throw(bad_hmean, bad_gmean) {
double means(double a, double b) throw(bad_hmean, bad_gmean) {
	double am, hm, gm;
	Demo d2("found in means()");
	am = (a+b)/2.0;	// arithmetic mean
	//	hm = hmean(a, b);
	//	gm = gmean(a, b);
	///*
	try {
		hm = hmean(a, b);
		gm = gmean(a, b);
	} 
	catch(bad_hmean &bg) {
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;		// rethrows the exception
	}
	//*/
	d2.show();
	return (am + hm + gm) /3.0;
}


