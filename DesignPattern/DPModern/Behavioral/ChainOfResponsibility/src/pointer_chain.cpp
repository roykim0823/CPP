#include "pointer_chain.h"

int main()
{
  	Creature goblin{ "Goblin", 1, 1 };
  	CreatureModifier root{ goblin };
  	DoubleAttackModifier r1{ goblin };
  	DoubleAttackModifier r1_2{ goblin };
  	IncreaseDefenseModifier r2{ goblin };
    NoBonusesModifier nb{ goblin }; // effectively Command objects

  //root.add(&nb);	// effective only after it is added
  root.add(&r1);
  root.add(&r1_2);
  root.add(&r2);

  root.handle(); 	// annoying
  cout << goblin << endl;

  return 0;
}
