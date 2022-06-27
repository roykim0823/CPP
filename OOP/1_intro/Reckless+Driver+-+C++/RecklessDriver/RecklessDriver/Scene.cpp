#include "Scene.h"
#include "FireHydrant.h"
#include "LetterBox.h"
#include "Sedan.h"
#include "Van.h"
#include <iostream>
#include <thread>


#include "Armor.h"
#include "HealthKit.h"
#include "PowerupFactory.h"
#include "SideObjectFactory.h"

namespace RecklessDriver {
	Scene::Scene() :m_Engine(m_rd()) {
	}


	void Scene::GenerateSideObjects()
	{
		switch (m_pPlayer->GetPlayerHealth().GetPlayerState()) {
		case PlayerState::HEALTHY:
			if (sideObjects.size() > 6) {
				sideObjects.erase(sideObjects.begin());
			}
			break ;
		case PlayerState::INJURED:
			while (sideObjects.size() > 4) {
				sideObjects.erase(sideObjects.begin());
			}
			break ;
		case PlayerState::CRITICAL:
			while (sideObjects.size() > 2) {
				sideObjects.erase(sideObjects.begin());
			}
			break ;
		case PlayerState::DEAD:
			break ;
		}
		
		std::uniform_int_distribution<int> dist(0, SIDEOBJECT_COUNT - 1);
		sideObjects.push_back(SideObjectFactory::GetInstance().CreateSideObject(dist(m_Engine)));
	}

	void Scene::GenerateTraffic()
	{
		switch (m_pPlayer->GetPlayerHealth().GetPlayerState()) {
		case PlayerState::HEALTHY:
			if (trafficObjects.size() > 6) {
				trafficObjects.erase(trafficObjects.begin());
			}
			break ;
		case PlayerState::INJURED:
			while (trafficObjects.size() > 4) {
				trafficObjects.erase(trafficObjects.begin());
			}
			break ;
		case PlayerState::CRITICAL:
			while (trafficObjects.size() > 2) {
				trafficObjects.erase(trafficObjects.begin());
			}
			break ;
		case PlayerState::DEAD:
			break ;
		}
		
		std::uniform_int_distribution<int> dist(0, TRAFFIC_COUNT - 1);
		Vehicle* p_traffic_car{};
		switch (dist(m_Engine))
		{
		case 0://Sedan
			p_traffic_car = new Sedan(5, 10);
			break;
		case 1://Van
			p_traffic_car = new Van(8, 13);
			break;
		}
		trafficObjects.push_back(p_traffic_car);
	}

	
	
	void Scene::GeneratePowerups() {
		int spawnIndex{} ;
		
		switch (m_pPlayer->GetPlayerHealth().GetPlayerState()) {
		case PlayerState::HEALTHY:
			{
			std::uniform_int_distribution<> dist{0, 7} ;
			spawnIndex = dist(m_Engine) ;
		}
			break ;
		case PlayerState::INJURED:
			{
			std::uniform_int_distribution<> dist{0, 4} ;
			spawnIndex = dist(m_Engine) ;
		}
			break ;
		case PlayerState::CRITICAL:
			{
			std::uniform_int_distribution<> dist{0, 2} ;
			spawnIndex = dist(m_Engine) ;
		}
			break ;
		case PlayerState::DEAD:
			spawnIndex = 100 ;
			break ;
		}
		if (spawnIndex < Powerup::POWERUP_COUNT) {
			if (spawnIndex != 0 && m_pPlayer->GetPowerup()->IsActive())
				return;
			PowerupFactory::CreatePowerup(spawnIndex)->OnCollision(m_pPlayer);
		}
	}
	void Scene::CreatePowerup(int index) {
		
	}
	void Scene::DisplaySideObjects()
	{
		std::cout << ">>>>> SIDEOBJECTS <<<<<<" << std::endl;
		for (const auto* p : sideObjects) {
			std::cout << p->GetName() << std::endl;
		}
		std::cout << std::endl;
	}

	void Scene::DisplayTraffic()
	{
		std::cout << ">>>>> TRAFFIC <<<<<<" << std::endl;
		for (const auto* p : trafficObjects) {
			std::cout << p->GetName() << std::endl;
		}
		std::cout << std::endl;
	}
	Scene::~Scene()
	{
	}
	void Scene::Start(Player* pPlayer) {
		m_pPlayer = pPlayer;
	}
	void Scene::Execute() {


		GenerateSideObjects();
		GenerateTraffic();
		GeneratePowerups() ;
		DisplaySideObjects();
		DisplayTraffic();
		Collide();
	}

	void Scene::Collide()
	{
		std::uniform_int_distribution<int> dist(0, NPC_TYPES - 1);
		std::uniform_int_distribution<int> distSideObjects(0, sideObjects.size() - 1);
		std::uniform_int_distribution<int> distTrafficObjects(0, trafficObjects.size() - 1);
		GameObject* pGo = nullptr;
		switch (dist(m_Engine))
		{
		case 0://Sideobject
			pGo = sideObjects[distSideObjects(m_Engine)];
			break;
		case 1://Traffic
			pGo = trafficObjects[distTrafficObjects(m_Engine)];
			break;
		default:
			break;
		}
		if (pGo != nullptr) {
			pGo->OnCollision(m_pPlayer);

		}
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}

}
