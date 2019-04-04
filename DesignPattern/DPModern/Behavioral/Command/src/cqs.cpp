#include "cqs.h"
#include <iostream>
#include <algorithm> 	// for for_each

using namespace std;

int main() {
	Creature c(100, 200);
	int strength, agility;

	cout << "Init" << endl;
	cout << "strength = " << c.get_strength() << ", agility = " << c.get_agility() << endl;
    c.set_strength(111);
    c.set_agility(222);
	cout << "Set" << endl;
	cout << "strength = " << c.get_strength() << ", agility = " << c.get_agility() << endl;

	return 0;
}
