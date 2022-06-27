#include "GameManager.h"
#include <iostream>
#include "PlayerVehicle.h"
#include "Player.h"
#include "Scene.h"
#include <thread>
#include <cstdlib>
namespace RecklessDriver {
	
	void GameManager::NewGame()
	{
		//Choose vehicle
		PlayerVehicle * pVehicle = new PlayerVehicle("Sedan", 5, 70, 4);
		//Create a player object
		Player *pPlayer = new Player(100, pVehicle);
		pPlayer->SetTag("Player") ;
		//Prepare the scenery
		Scene scene;
		scene.Start(pPlayer);
		//Run a loop
		while (pPlayer->IsAlive()) {
			system("cls");
			//Generate game objects (sideobject, traffic, etc)
			scene.Execute();
			pPlayer->Drive();
		}
	}

	void GameManager::EndGame()
	{
		std::cout << "Total cash accumulated : " << m_Cash << std::endl;
	}

	GameManager::GameManager()
	{
	}


	GameManager::~GameManager()
	{
	}
}