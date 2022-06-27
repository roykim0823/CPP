#include "HealthKit.h"

#include <iostream>
#include "Player.h"
void RecklessDriver::HealthKit::OnCollision(GameObject* other) {
	if(other->GetTag() == "Player") {
		std::cout << "***************************************\n" ;
		std::cout << "************* HEALTHKIT ***************\n" ;
		std::cout << "***************************************\n" ;
		Player *p = (Player *)other ;
		auto newHealth = p->GetPlayerHealth().GetUnits() + 25;
		p->GetPlayerHealth().SetUnits(newHealth) ;
	}
}

void RecklessDriver::HealthKit::ApplyPowerup(Player* p, int damage, int cash) {
}
