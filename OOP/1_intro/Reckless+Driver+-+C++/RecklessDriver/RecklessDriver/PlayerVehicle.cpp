#include "PlayerVehicle.h"

namespace RecklessDriver {

	PlayerVehicle::PlayerVehicle(const std::string name, int handling, int topspeed, int strength):
		m_name(name),
		m_handling(handling),
		m_topSpeed(topspeed),
		m_strength(strength)
	{
	}


}