#include "Game.h"


Game::Game()
{
	
	choice = 0;
	running = true;
	playChoice = 0;
	playStarted = false;

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
	cout << "1: Character Info" << endl;
	cout << "2: Play" << endl << endl; 

	cout << endl << "Choice: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 0:
		running = false;
		break;

	case 1:
		character.printPlayeStats();
		break;

	case 2:
		PlayGame();
		break;

	default:
		break;
	}

	
}
void Game::PlayGame()
{
	cout << "Welcome to Murkwood Sacntuary Adventurer! Don't let the name fool you. It is far from a sacntuary " << endl << endl; 
	cout << "MurkWood is a realm cloaked in an ethereal mist that shrouds the ancient tree in an otherworldly haze. " << endl;
	cout << "As you step cautiously through the forest, the air is thick with a mysterious energy, " << endl;
	cout << "and the soft crunch of fallen leaves beneath your feet echoes through the silence. You hear no other life around you.  " << endl;
	cout << "The twisted branches above form an intricate canopy that filters the pale moolight, casting an earie glow  " << endl;
	cout << "on the damp forest floor.  " << endl << endl; 
	cout << "In the distance lies an imposing mansion, its' dark silhouette imposing against the fog laden backdrop.  " << endl;
	cout << "A palpable aura of corruption emanates from its' walls, whispering tales of secrets, long buried within.  " << endl << endl; 
	cout << "To the Left, a winding stretches endlessly into the unknown, with each visible\nbend revealing more mysteries than the last.  " << endl;
	cout << "The air is filled with anticipation as you consider what lies beyond the seemingly infinite trail.  " << endl << endl; 
	cout << "To the right, a creature of unknown origin lurks in the shadows. Its' eyes gleam with an otherworldly intelligence,  " << endl;
	cout << "and the air around it crackles with a sense of danger. you take a deap breath, the crisp cold air burns inside your lungs, " << endl;
	cout << "your nose is filled with the scent of death. Should you app  " << endl;
	cout << "As you step  " << endl;
	cout << "As you step  " << endl;
	cout << "As you step  " << endl;
	cout << "As you step  " << endl;
	cout << "As you step  " << endl;
	cout << "As you step  " << endl;

	cout << "0: Quit" << endl; 
	cout << "1: Character Info" << endl; 
	cout << "2: Play" << endl << endl;


	//int playChoice;
	cout << endl << "Choice: ";
	cin >> choice;
	cout << endl;
	playStarted = true;
	switch (playChoice)
	{
	case 0:
		running = false;
		break;

	case 1:
		character.printPlayeStats();
		break;

	

	default:
		break;
	}

}