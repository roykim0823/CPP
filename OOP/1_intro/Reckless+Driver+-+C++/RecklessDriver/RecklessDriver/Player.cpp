#include "Player.h"
#include <iostream>
#include <thread>

#include "GameManager.h"
namespace RecklessDriver {

	Player::Player(int health, PlayerVehicle *pVehicle): m_pVehicle(pVehicle)
	{
		m_PlayerHealth.SetUnits(health) ;
		//SetName("Player");
	}


	Player::~Player()
	{
	}
	void Player::ApplyDamage(int damage, int cash) {
		m_pPowerup->ApplyPowerup(this, damage, cash) ;
		
	}
	void Player::Drive()
	{
		std::cout << "\nPlayer is driving [Health=" <<m_PlayerHealth.GetUnits() << ']';
		std::cout << "[Powerup:" << m_pPowerup->GetPowerupDetails() << ']'<< std::endl ;
		for (int i = 0; i < 10; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			std::cout << ".";
		}
		std::cout << std::endl; 
	}
}