#include "FireHydrant.h"
#include "GameManager.h"
#include "LetterBox.h"
#include "Player.h"
#include "SideObject.h"
#include "SideObjectFactory.h"

void Initialize() {
	RecklessDriver::SideObjectFactory::GetInstance().RegisterCallback(0, []()-> RecklessDriver::SideObject * {
		return new RecklessDriver::LetterBox{8,13} ;
	});
	RecklessDriver::SideObjectFactory::GetInstance().RegisterCallback(1, []()-> RecklessDriver::SideObject * {
		return new RecklessDriver::FireHydrant{5, 10} ;
	});
}
int main() {
	Initialize() ;
	RecklessDriver::GameManager::GetInstance().NewGame();
	return 0;
}


//class GameObject {
//public:
//	virtual void OnCollision(GameObject other) {
//
//	}
//};
////SideObject does not override OnCollision
//class SideObject : public GameObject {
//	//Attributes
//	//Methods
//};
//class FireHydrant : public SideObject {
//	//Note:override is a C++11 keyword
//public:
//	void OnCollision(GameObject other)override  {
//		//Implementation
//	}
//};
//
//void DoCollision(GameObject *pGo) {
//	pGo->OnCollision(player);
//}
