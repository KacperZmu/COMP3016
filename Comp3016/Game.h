#pragma once
#include "Character.h"
#include "Functions.h"
#include <ctime>



class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void PlayGame(const std::string& playerName);
	void MoveMansion(const std::string& playerName);
	void LeftCreature();
	void DeathScreen(const std::string& playerName);
	void KilledCreature(const std::string& playerRace);
	//Accessors
	inline bool getRunning() const { return this->running; }
	//Modifiers
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

	//Character
	Character character;

};

