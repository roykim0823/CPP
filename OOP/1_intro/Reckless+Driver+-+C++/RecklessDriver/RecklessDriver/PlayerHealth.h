#pragma once
#include "PlayerState.h"

class PlayerHealth
{
private:
	int m_HealthUnits{100} ;
	PlayerState m_State {PlayerState::HEALTHY} ;
	void UpdateState() ;
public:
	int GetUnits()const ;
	void SetUnits(int units) ;
	PlayerState GetPlayerState()const ;
};

