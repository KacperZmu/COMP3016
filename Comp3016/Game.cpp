#include "Game.h"


Game::Game()
{
	
	choice = 0;
	running = true;

}

Game::~Game()
{

}

void Game::initGame()
{
	string name;
	string race;
	cout << "Enter Name for your Character: ";
	getline(cin, name);
	cout << "Enter your Character race: "; 
	getline(std::cin, race);
	character.init(name, race);
	

}

//Functions
void Game::mainMenu()
{
	cout << "= Main Menu =" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Go Right" << endl;
	cout << "2: Go Left" << endl;
	cout << "3: Go Forward" << endl;
	cout << "4: Go Back" << endl;
	cout << "5: Rest" << endl;
	cout << "6: Character Info" << endl << endl;

	cout << endl << "Choice: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 0:
		running = false;
		break;

	case 6:
		character.printPlayeStats();
		break;

	default:
		break;
	}
}