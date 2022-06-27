#include "Sedan.h"
#include "Player.h"
#include <iostream>
namespace RecklessDriver {

	Sedan::Sedan(int _damage, int _cash):Vehicle(_damage, _cash)
	{
		SetName("Sedan");
	}

	void Sedan::OnCollision(GameObject *other)
	{
		if (other->GetTag() == "Player") {
			Player *p = (Player *)other;
				std::cout << "#### COLLISION ->[Sedan] Sparks flying" << std::endl;
				p->ApplyDamage(GetDamage(), GetCash());
		}
	}
}
