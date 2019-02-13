#include <iostream>
#include <array>
#include <numeric>		// for accumulate
#include <algorithm> 	// for max_element
#include <cmath>

using namespace std;

/* the impl. is unpleasant:
	1. When calculating the sum of all statistics, 
	   it is easy to make a mistake and forget one of them.
	2. When calculating the average, it uses a bona fide magic number 3.0 that
	   corresponds to the number of fields that are used in the calculation
	3. When calculating the maximum, I have to construct pairs-of-pairs of 
	   std::max() calls
*/
class Creature_Naive
{
  int strength, agility, intelligence;
public:
  int get_strength() const 	{ return strength; }
  int get_agility() const 	{ return agility; }
  int get_intelligence() const 	{ return intelligence; }

  void set_strength(int strength) 	{ this->strength = strength; }
  void set_agility(int agility) 	{ this->agility = agility; }
  void set_intelligence(int intelligence) { this->intelligence = intelligence; }

  // sum, average, max.
  double sum() const {
    return strength + agility + intelligence;
  }

  double average() const {
    return sum() / 3.0;
  }

  int max() const {
    return ::max(::max(strength, agility), intelligence);
  }
};

// array-backed properties
class Creature
{
  enum Abilities { str, agl, intl, count }; 	// count for the size
  array<int, count> abilities;
public:
  int get_strength() const 		{ return abilities[str]; }
  void set_strength(int value) 	{ abilities[str] = value; }

  int get_agility() const 		{ return abilities[agl]; }
  void set_agility(int value) 	{ abilities[agl] = value; }

  int get_intelligence() const 	{ return abilities[intl]; }
  void set_intelligence(int value) { abilities[intl] = value; }

  int sum() const {
    return accumulate(abilities.begin(), abilities.end(), 0);
  }

  double average() const {
    return sum() / (double)count;
  }

  int max() const {
    return *max_element(abilities.begin(), abilities.end());
  }
};


int main(int ac, char* av[])
{
  Creature_Naive orc_n;
  orc_n.set_strength(16);
  orc_n.set_agility(11);
  orc_n.set_intelligence(9);

  cout << "The orc has an average stat of "
       << orc_n.average()
       << " and a maximum stat of "
       << orc_n.max()
       << endl;
  
  Creature orc;
  orc.set_strength(16);
  orc.set_agility(11);
  orc.set_intelligence(9);

  cout << "The orc has an average stat of "
       << orc.average()
       << " and a maximum stat of "
       << orc.max()
       << endl;

  return 0;
}
