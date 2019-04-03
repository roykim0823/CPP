#include "broker_chain.h"

// similar idea, but Query instead of Command
int main(int ac, char* av)
{
  	Game game;
  	Creature goblin{ game, "Strong Goblin", 2, 2 };

  	cout << goblin << endl;

  	{
    	DoubleAttackModifier dam{ game, goblin };
    	cout << goblin << endl;
  	}

  	cout << goblin << endl;
  
  	return 0;
}
