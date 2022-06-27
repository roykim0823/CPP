#pragma once
#include "SideObject.h"
namespace RecklessDriver {
	class FireHydrant :
		public SideObject
	{
	public:
		FireHydrant(int _damage, int _cash);
		~FireHydrant();
		void OnCollision(GameObject *other);
	};
}

