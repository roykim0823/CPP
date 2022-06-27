#pragma once
#include "SideObject.h"
namespace RecklessDriver {
	class LetterBox :
		public SideObject
	{
	public:
		LetterBox(int _damage, int _cash);
		~LetterBox();
		void OnCollision(GameObject *other)override;
	};
}

