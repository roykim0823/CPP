#pragma once
#include <vector>
#include "SideObject.h"
#include "Vehicle.h"
#include "Player.h"
#include <random>
namespace RecklessDriver {
	class Scene
	{
		const int SIDEOBJECT_COUNT = 2;
		const int TRAFFIC_COUNT = 2;
		const int NPC_TYPES = 2;
		std::vector<SideObject*> sideObjects;
		std::vector<Vehicle*> trafficObjects;
		Player* m_pPlayer;
		void CreatePowerup(int index);

		std::random_device m_rd;
		std::default_random_engine m_Engine;
		void GenerateSideObjects();
		void GenerateTraffic();
		void DisplaySideObjects();
		void DisplayTraffic();
		void GeneratePowerups();
	public:
		Scene();
		~Scene();
		void Start(Player* pPlayer);
		void Execute();
		void Collide();
	};
}
