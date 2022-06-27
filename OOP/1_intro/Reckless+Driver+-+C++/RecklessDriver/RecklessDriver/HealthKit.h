#pragma once
#include "Powerup.h"
namespace RecklessDriver {
	class HealthKit :
		public Powerup
	{

	public:
		void OnCollision(GameObject* other) override;
		void ApplyPowerup(Player* p, int damage, int cash) override;
		std::string GetPowerupDetails() const override {
			return "HEALTHKIT" ;
		}
	};
}

