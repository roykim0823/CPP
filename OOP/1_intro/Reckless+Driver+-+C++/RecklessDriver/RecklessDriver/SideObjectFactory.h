#pragma once
#include <map>

namespace RecklessDriver {
	class SideObject;
	using Callback = SideObject * (*)();
	class SideObjectFactory
	{
		std::map<int, Callback> m_Callbacks;
	public:
		SideObject* CreateSideObject(int key);
		void RegisterCallback(int key, Callback callback) ;
		static SideObjectFactory & GetInstance() ;
	};
}

