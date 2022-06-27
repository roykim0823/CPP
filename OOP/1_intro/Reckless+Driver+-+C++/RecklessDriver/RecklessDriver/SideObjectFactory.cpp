#include "SideObjectFactory.h"

RecklessDriver::SideObject* RecklessDriver::SideObjectFactory::CreateSideObject(int key) {
	return m_Callbacks[key]() ;
}

void RecklessDriver::SideObjectFactory::RegisterCallback(int key, Callback callback) {
	m_Callbacks[key] = callback ;
}

RecklessDriver::SideObjectFactory& RecklessDriver::SideObjectFactory::GetInstance() {
	static SideObjectFactory instance ;
	return instance ;
}
