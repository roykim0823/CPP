#include "Armor.h"

#include <iostream>

#include "GameManager.h"
#include "Player.h"
void RecklessDriver::Armor::OnCollision(GameObject* other) {
	if(other->GetTag() == "Player") {
		std::cout << "*************************************\n" ;
		std::cout << "************** ARMOR ****************\n" ;
		std::cout << "*************************************\n" ;
		Player *p = (Player*)other ;
		p->SetPowerup(this) ;
		
	}
}

void RecklessDriver::Armor::ApplyPowerup(Player* p, int damage, int cash) {
	auto totalDamage = p->GetVehicle()->GetStrength() + damage/2 ;
	p->GetPlayerHealth().SetUnits(p->GetPlayerHealth().GetUnits()-totalDamage) ;
	GameManager::GetInstance().AddCash(cash) ;
	if(--m_CountDown == 0) {
		p->SetPowerup(new NoPowerup{}) ;
	}
}
