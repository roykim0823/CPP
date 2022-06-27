#pragma once
#include "GameObject.h"
#include "NoPowerup.h"
#include "PlayerHealth.h"
#include "PlayerVehicle.h"
#include "Powerup.h"
#include "PowerupFactory.h"

namespace RecklessDriver {
	class Player : public GameObject
	{
		PlayerVehicle *m_pVehicle;
		PlayerHealth m_PlayerHealth ;
		Powerup *m_pPowerup{PowerupFactory::CreatePowerup(-1)} ;
	public:
		PlayerHealth & GetPlayerHealth() {
			return m_PlayerHealth ;
		}
		PlayerVehicle * GetVehicle()const {
			return m_pVehicle ;
		}
		Powerup *GetPowerup()const {
			return m_pPowerup ;
		}
		void SetPowerup(Powerup *p) {
			m_pPowerup = p ;
		}
		Player(int health, PlayerVehicle *pVehicle);
		~Player();
		bool IsAlive() {
			return m_PlayerHealth.GetPlayerState() != PlayerState::DEAD;
		}
		void Accelerate() {
			m_pVehicle->Up();
		}
		void Brake() {
			m_pVehicle->Down();

		}
		void SteerRight() {
			m_pVehicle->Right();

		}
		void SteerLeft() {
			m_pVehicle->Left();

		}
		void ApplyDamage(int damage, int cash);
		void Drive() ;
	};

}
