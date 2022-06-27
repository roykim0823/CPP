#pragma once
#include "Vehicle.h"
namespace RecklessDriver {
	class Van :
		public Vehicle
	{
	public:
		Van(int _damage, int _cash);
		void OnCollision(GameObject *other)override;
	};
}

