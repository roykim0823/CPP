#include "FireHydrant.h"
#include "Player.h"
#include <iostream>
namespace RecklessDriver {
	FireHydrant::FireHydrant(int _damage, int _cash):SideObject(_damage, _cash)
	{
		SetName("FireHydrant");
	}


	FireHydrant::~FireHydrant()
	{
	}

	void FireHydrant::OnCollision(GameObject *other)
	{
		if (other->GetTag() == "Player") {
			Player *p = (Player *)other;
			if (count == 0) {
				std::cout << "#### COLLISION ->[FireHydrant] Fountain" << std::endl; 
				p->ApplyDamage(GetDamage(), GetCash());
			}
			else {
				std::cout << "#### COLLISION ->[FireHydrant] Collided again" << std::endl;
				p->ApplyDamage(GetDamage(), GetCash() * count);
			}
		}
	}
}
