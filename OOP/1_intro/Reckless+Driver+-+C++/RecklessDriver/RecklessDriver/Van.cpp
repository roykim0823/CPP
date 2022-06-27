#include "Van.h"
#include <iostream>
#include "Player.h"
namespace RecklessDriver {

	Van::Van(int _damage, int _cash) :Vehicle(_damage, _cash)
	{
		SetName("Van");
	}

	void Van::OnCollision(GameObject *other)
	{
		if (other->GetTag() == "Player") {
			Player *p = (Player *)other;
			std::cout << "#### COLLISION ->[Van] Milk bottles falling" << std::endl;
			p->ApplyDamage(GetDamage(), GetCash());
		}
	}
}

