#pragma once
#include "Powerup.h"
namespace RecklessDriver {
	class NoPowerup :
		public Powerup
	{

	public:
		void OnCollision(GameObject* other) override;
		void ApplyPowerup(Player* p, int damage, int cash) override;
		virtual bool IsActive()const{return false ;}
		
	};
}

