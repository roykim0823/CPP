#include "NoPowerup.h"

#include "GameManager.h"
#include "Player.h"
void RecklessDriver::NoPowerup::OnCollision(GameObject* other) {
}

void RecklessDriver::NoPowerup::ApplyPowerup(Player* p, int damage, int cash) {
	auto newHealth = p->GetPlayerHealth().GetUnits() - damage - p->GetVehicle()->GetStrength();
	p->GetPlayerHealth().SetUnits(newHealth);
	GameManager::GetInstance().AddCash(cash);
}
