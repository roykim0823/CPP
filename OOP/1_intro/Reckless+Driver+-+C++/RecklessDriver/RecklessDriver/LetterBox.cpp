#include "LetterBox.h"
#include "Player.h"
#include <iostream>

namespace RecklessDriver {
	LetterBox::LetterBox(int _damage, int _cash):SideObject(_damage, _cash)
	{
		SetName("LetterBox");
	}


	LetterBox::~LetterBox()
	{
	}
	void LetterBox::OnCollision(GameObject *other)
	{
		if (other->GetTag() == "Player") {
			Player *p = (Player *)other;
			if (count == 0) {
				std::cout << "#### COLLISION ->[LetterBox] Letters falling" << std::endl;
				p->ApplyDamage(GetDamage(), GetCash());
			}
			else {
				std::cout << "#### COLLISION ->[LetterBox] Collided again" << std::endl;
				p->ApplyDamage(GetDamage(), GetCash() * count);
			}
		}
	}
}
