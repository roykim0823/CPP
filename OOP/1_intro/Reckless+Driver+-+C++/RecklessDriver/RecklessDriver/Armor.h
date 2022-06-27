#pragma once
#include "Powerup.h"
#include <sstream>
namespace RecklessDriver{
class Armor :
	public Powerup
{

public:
	void OnCollision(GameObject* other) override;
	void ApplyPowerup(Player* p, int damage, int cash) override;

	std::string GetPowerupDetails() const override {
		std::ostringstream ostr{} ;
		ostr << "ARMOR {" << m_CountDown << '}' ;
		return ostr.str() ;
	}
};
}
