#pragma once
namespace RecklessDriver {
	class GameManager
	{
		int m_Cash;
		GameManager();
	public:
		int GetCash()const {
			return m_Cash;
		}
		void AddCash(int amount) {
			m_Cash += amount;
		}
		void NewGame();
		void EndGame();
		~GameManager();
		static GameManager & GetInstance() {
			//Meyer's singleton
			static GameManager instance;
			return instance;
		}
	};

}