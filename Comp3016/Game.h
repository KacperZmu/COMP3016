#pragma once
#include "Character.h"
#include "Functions.h"
#include <ctime>



class Game
{
public:
	Game();
	virtual ~Game();

	

	
	void initGame();
	void mainMenu();
	void PlayGame(const std::string& playerName);
	void MoveMansion(const std::string& playerName);
	void LeftCreature();
	void DeathScreen(const std::string& playerName);
	void KilledCreature(const std::string& playerRace);
	void ShowOffMansions();
	void Sacrifice();
	void SoldierOn();
	void ManCoruption();
	void PhanAttack(const std::string& playerName);
	void PhanBattle(const std::string& playerName);
	void PhanBattleAfter();

	
	inline bool getRunning() const { return this->running; }
	
	
private:
	int choice;
	bool running;
	int playerChoice;
	bool playStarted;
	int moveMansion;
	bool mansionStarted;
	int leftCreature;
	bool leftCreatureStarted;
	bool deathScreenStarted;
	int DeathScr;
	int killedCreature;
	bool killedCreatureStarted;
	int ShowOffMansion;
	bool ShowOffMansionStarted;
	int sacrifice;
	bool SacrificeStarter;
	int soledierOn;
	bool soldierOnStarter;
	int manCorupt;
	bool manCoruptStarted;
	int phanAttack;
	bool phanAttackStarted;
	int phanBattle;
	bool phanBattleStarted;
	int phanBattleAfter;
	bool phanBattleAfterStarted;

	//Character
	Character character;

};

