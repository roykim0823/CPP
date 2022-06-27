#pragma once
#include "GameObject.h"
namespace RecklessDriver {
	class Player;
	class Powerup :
		public GameObject
	{
		const int DURATION=5 ;
	protected:
		int m_CountDown = DURATION;
	public:
		virtual void ApplyPowerup(Player* p, int damage, int cash) = 0;
		static const int POWERUP_COUNT = 2 ;
		virtual bool IsActive()const{return true ;}
		virtual std::string GetPowerupDetails()const {return "DEFAULT" ;}
	};
}
