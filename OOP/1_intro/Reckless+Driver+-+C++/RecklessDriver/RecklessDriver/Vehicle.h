#pragma once
#include "GameObject.h"
namespace RecklessDriver {
	class Vehicle :
		public GameObject
	{
		int damage;
		int cash;
	public:
		Vehicle(int _damage, int _cash);
		~Vehicle();
		int GetDamage()const {
			return damage;
		}
		int GetCash()const {
			return cash;
		}
	};
}

