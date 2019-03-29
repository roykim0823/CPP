#include "property.h"
#include <iostream>

using namespace std;

struct Creature
{
  Property<int> strength{ 10 };
  Property<int> agility{ 5 };
};

void property_proxy()
{
  Creature creature;
  creature.agility = 20;
  cout << creature.agility << endl;
}

int main()
{
	Creature creature;
	creature.agility = 20;
	auto x = creature.strength;
	cout << "strength = " << x << endl;
	cout << "agility  = " << creature.agility << endl;

  	return 0;
}
