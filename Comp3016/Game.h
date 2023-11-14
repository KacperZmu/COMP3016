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
	void PlayGame();

	//Accessors
	inline bool getRunning() const { return this->running; }
	//Modifiers
private:
	int choice;
	bool running;
	int playChoice;
	bool playStarted;

	//Character
	Character character;

};

