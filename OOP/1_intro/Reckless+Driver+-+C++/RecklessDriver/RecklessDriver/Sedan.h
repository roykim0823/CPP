#pragma once
#include "Vehicle.h"
namespace RecklessDriver {
	class Sedan :
		public Vehicle
	{
	public:
		Sedan(int _damage, int _cash);
		void OnCollision(GameObject *other)override;
	};
}
