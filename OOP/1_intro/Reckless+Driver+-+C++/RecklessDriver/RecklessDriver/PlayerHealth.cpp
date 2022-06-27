#include "PlayerHealth.h"


#include <iostream>
#include <string>


void PlayerHealth::UpdateState() {
	if(m_HealthUnits > 70) {
		m_State = PlayerState::HEALTHY ;
	}else if(m_HealthUnits >= 25 && m_HealthUnits <= 70) {
		m_State = PlayerState::INJURED ;
	}else if(m_HealthUnits >= 1 && m_HealthUnits < 25) {
		m_State = PlayerState::CRITICAL ;
	}else {
		m_State = PlayerState::DEAD ;
	}
	std::string stateName{} ;
	switch (m_State) {
	case PlayerState::HEALTHY:
		stateName = "HEALTHY" ;
		break ;
	case PlayerState::INJURED:
		stateName = "INJURED" ;
		break ;
	case PlayerState::CRITICAL:
		stateName = "CRITICAL" ;
		break ;
	case PlayerState::DEAD:
		stateName = "DEAD" ;
		break ;
	}
	std::cout << "Current State :" << stateName << '\n' ;
}

int PlayerHealth::GetUnits() const {
	return m_HealthUnits ;
}

void PlayerHealth::SetUnits(int units) {
	m_HealthUnits = units < 0 ? 0 : units ;
	UpdateState() ;
}

PlayerState PlayerHealth::GetPlayerState() const {
	return m_State ;
}
