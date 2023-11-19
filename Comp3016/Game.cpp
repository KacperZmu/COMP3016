#include "Game.h"
#include <random>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Printing lines from txt file - used for story
vector<string> loadSpecificLines(const string& fileName, int startLine, int endLine) {
	vector<string> linesToLoad;
	ifstream inputFile(fileName);

	if (!inputFile.is_open()) {
		cerr << "error opening the file" << fileName << endl;
		return linesToLoad;
	}

	string line;
	int currentLineNumber = 1;

	while (getline(inputFile, line) && currentLineNumber <= endLine) {
		if (currentLineNumber >= startLine && currentLineNumber <= endLine) {
			linesToLoad.push_back(line);
		}

		++currentLineNumber;
	}
	inputFile.close();
	return linesToLoad;

}

void processLines(const vector<string>& lines) {
	for (const auto& loadedLines : lines) {
		cout << loadedLines << endl;
	}
}

Game::Game()
{
	
	choice = 0;
	running = true;
	playStarted = false;
	mansionStarted = false;
	playerChoice = 0;
	moveMansion = 0;
	leftCreature = 0;
	leftCreatureStarted = false;
	deathScreenStarted = false;
	DeathScr = 0;
	killedCreature = 0;
	killedCreatureStarted = false;
	ShowOffMansion = 0;
	ShowOffMansionStarted = false;
	sacrifice = 0;
	SacrificeStarter = false;
	soledierOn = 0;
	soldierOnStarter = false;
	manCorupt = 0;
	manCoruptStarted = false;
	phanAttack = 0;
	phanAttackStarted = false;
	phanBattle = 0;
	phanBattleStarted = false;
	phanBattleAfter = 0;
	phanBattleAfterStarted = false;

	
	

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
	system("CLS");
	

}

//Functions
void Game::mainMenu()
{
	cout << "= Main Menu =" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Character Info" << endl;
	cout << "2: Play" << endl << endl; 
	
	// getting user input, checking if valid
	cout << endl << "Choice: ";
	while (!(cin >> choice) || (choice < 0 || choice > 2))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;

	
	//switch cases - depending on user choice, do the following
	switch (choice)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		character.printPlayeStats();
		break;

	case 2:
		system("CLS");
		PlayGame(character.getName());
		break;

	default:
		break;
	}

	
}
void Game::PlayGame(const std::string& playerName)
{
	//uses the starting print - set which lines to print
	string fileName = "Story.txt";
	vector<string> lines1To30 = loadSpecificLines(fileName, 1, 30);
	processLines(lines1To30);
	character.ResetHealth();

	cout << "0: Quit" << endl; 
	cout << "1: Character Info" << endl; 
	cout << "2: Head Towards the Mansion" << endl;
	cout << "3: Approach the Creature..." << endl; 
	
	

	
	cout << endl << "Choice: ";
	while (!(cin >> playerChoice) || (playerChoice < 0 || playerChoice > 3))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	playStarted = true;
	mansionStarted = false;
	switch (playerChoice)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		character.printPlayeStats();
		break;
	case 2:
		system("CLS");
		mansionStarted = true;
		MoveMansion(character.getName());
		break;
	case 3:
		system("CLS");
		leftCreatureStarted = true;
		LeftCreature(); 
		break;

	

	default:
		break;
	}

}

void Game::LeftCreature()
{
	string fileName = "Story.txt";
	vector<string> lines31To55 = loadSpecificLines(fileName, 31, 55);
	processLines(lines31To55);
	


	cout << "0: Quit" << endl;
	cout << "1: Run Away" << endl;
	cout << "2: Attack the creature" << endl;
	




	cout << endl << "Choice: ";
	while (!(cin >> leftCreature) || (leftCreature < 0 || leftCreature > 2))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	leftCreatureStarted = true;
	playStarted = false;
	switch (leftCreature)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;
	case 2: {
		system("CLS");
		playerChoice = 0;
		leftCreature = 0;
		//randomly choose number, if over 6, player kills creature, else they die
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 20);
		int randomNumber = dis(gen);
		if (randomNumber > 6) {
			KilledCreature(character.getRace());
			break;
		}
		else {
			DeathScreen(character.getName());
			break;
		}
	   }



	default:
		break;
	}

}

void Game::KilledCreature(const std::string& playerRace)
{
	string fileName = "Story.txt";
	vector<string> lines56To73 = loadSpecificLines(fileName, 56, 73);
	processLines(lines56To73);
	cout << playerRace << endl << endl << endl << endl << endl; 

	cout << "0: Quit" << endl;
	cout << "1: Soldier On" << endl;
	cout << "2: Embrace the Guardians Legacy" << endl;
	character.levelUp();




	cout << endl << "Choice: ";
	while (!(cin >> killedCreature) || (killedCreature < 0 || killedCreature > 2))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	leftCreatureStarted = false;
	killedCreatureStarted = true;
	switch (killedCreature)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		killedCreatureStarted = false;
		soldierOnStarter = true;
		SoldierOn();
		break;

	case 2:
		system("CLS");
		SacrificeStarter = true;
		killedCreatureStarted = false;
		killedCreature = 0;
		sacrifice = 0;
		Sacrifice();
		break;
	



	default:
		break;
	}

}

void Game::Sacrifice()
{
	string fileName = "Story.txt";
	vector<string> lines125To142 = loadSpecificLines(fileName, 125, 142);
	processLines(lines125To142);
	character.levelUp();
	

	cout << "0: Quit" << endl;
	cout << "1: Restart" << endl;
	



	cout << endl << "Choice: ";
	while (!(cin >> sacrifice) || (sacrifice < 0 || sacrifice > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	SacrificeStarter = true;
	
	
	switch (sacrifice)
	{
	case 0:
		running = false;
		break;
	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;




	default:
		break;
	}

}

void Game::SoldierOn()
{
	string fileName = "Story.txt";
	vector<string> lines145To163 = loadSpecificLines(fileName, 145, 163);
	processLines(lines145To163);





	cout << "0: Quit" << endl;
	cout << "1: Restart" << endl;






	cout << endl << "Choice: ";
	while (!(cin >> soledierOn) || (soledierOn < 0 || soledierOn > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	leftCreatureStarted = true;
	playStarted = false;
	switch (soledierOn)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;




	default:
		break;
	}

}


void Game::DeathScreen(const std::string& playerName)
{
	string fileName = "Story.txt";
	vector<string> lines74To75 = loadSpecificLines(fileName, 74, 75);
	processLines(lines74To75);
	
	



	cout << "0: Quit" << endl;
	cout << "1: Restart" << endl;
	





	cout << endl << "Choice: ";
	while (!(cin >> DeathScr) || (DeathScr < 0 || DeathScr > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	leftCreatureStarted = true;
	playStarted = false;
	switch (DeathScr)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;
	



	default:
		break;
	}

}


void Game::MoveMansion(const std::string& playerName)
{
	string fileName = "Story.txt";
	vector<string> lines79To98 = loadSpecificLines(fileName, 79, 98);
	processLines(lines79To98);
	
	cout << "0: Quit" << endl;
	cout << "1: Head Back" << endl;
	cout << "2: Show off your physical prowess" << endl;
	cout << "3: Attack the creature" << endl;
	
	


	
	cout << endl << "Choice: ";
	while (!(cin >> moveMansion) || (moveMansion < 0 || moveMansion > 3))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	mansionStarted = true;
	playStarted = false;
	switch (moveMansion)
	{
	case 0:
		running = false;
		break;

	
	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		moveMansion = 0;
		PlayGame(character.getName());
		break;
	case 2:
		system("CLS");
		playerChoice = 0;
		moveMansion = 0;
		ShowOffMansions();

	case 3:
		system("CLS");
		moveMansion = 0;
		mansionStarted = false;
		PhanAttack(character.getName());



	default:
		break;
	}

}


void Game::PhanAttack(const std::string& playerName)
{
	cout << playerName << endl;
	string fileName = "Story.txt";
	vector<string> lines191To198 = loadSpecificLines(fileName, 191, 198);
	processLines(lines191To198);
	character.levelUp();

	cout << "0: Quit" << endl;
	cout << "1: Fight" << endl;

	





	cout << endl << "Choice: ";
	while (!(cin >> phanAttack) || (phanAttack < 0 || phanAttack > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	phanAttackStarted = true;
	mansionStarted = false;
	switch (phanAttack)
	{
	case 0:
		running = false;
		break;


	case 1:
		system("CLS");
		PhanBattle(character.getName());

		
		break;
		

	default:
		break;
	}

}

void Game::PhanBattle(const std::string& playerName)
{
	int enemyHealth = 60;
	phanBattleStarted = true;
	// here we have a battle, while both have health, do this
	while (character.getHP() > 0 && enemyHealth > 0) {
		cout << "Phantom Health: " << enemyHealth << endl;
		cout << playerName << " Health: " << character.getHP() << " / " << character.getHPMax() << endl << endl << endl;


		cout << "0: Quit" << endl;
		cout << "1: Fight" << endl;

		cout << endl << "Choice: ";
		while (!(cin >> phanBattle) || (phanBattle < 0 || phanBattle > 1))
		{
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		phanBattleStarted = true;
		phanAttackStarted = false;
		switch (phanBattle)
		{
		case 0:
			running = false;
			break;


		case 1:
		{
			//random player damage is set per round, based on damage form the player class
			system("CLS");
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dis(character.getDamageMin(), character.getDamageMax());
			int playerDamage = dis(gen);

			//random danage is set, between 2 and 16 for the enemy
			uniform_int_distribution<> enemyDis(2, 16);
			int enemyDamage = enemyDis(gen);
			cout << playerName << " dealt " << playerDamage << " damage to the Phantom! " << endl;
			cout << "Phantom dealt " << enemyDamage << " " << playerName << endl << endl;
			//enemy takes damage chosen randomly for player damage
			enemyHealth -= playerDamage;

			//if enemy health 0, end battle and take player further
			if (enemyHealth <= 0)
			{
				cout << "You Defeated the Phantom!" << endl;
				character.levelUp();
				PhanBattleAfter();
			}
			//if the enemy still has health, take enemy damage from player health
			else
			{
				character.takeDamage(enemyDamage);

				if (character.getHP() <= 0)
				{
					cout << "You were defeated by the Phantom!" << endl << endl << endl;
					DeathScreen(character.getName());
				}
			}
			break;
		}


		default:
			break;
		}

	}	

}





void Game::ShowOffMansions()
{
	
	string fileName = "Story.txt";
	vector<string> lines100To103 = loadSpecificLines(fileName, 100, 103);
	processLines(lines100To103);
	string fileNames = "Story.txt";
	vector<string> lines246To283 = loadSpecificLines(fileNames, 246, 283);
	processLines(lines246To283);
	string fileNamee = "Story.txt";
	vector<string> lines104To122 = loadSpecificLines(fileNamee, 104, 122);
	processLines(lines104To122);
	character.levelUp();
	

	


	cout << "0: Quit" << endl;
	cout << "1: Head Back" << endl;
	cout << "2: Go Forth" << endl;
	




	cout << endl << "Choice: ";
	while (!(cin >> ShowOffMansion) || (ShowOffMansion < 0 || ShowOffMansion > 2))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	ShowOffMansionStarted = true;
	mansionStarted = false;
	switch (ShowOffMansion)
	{
	case 0:
		running = false;
		break;


	case 1:
		system("CLS");
		playStarted = true;
		ShowOffMansion = 0;
		moveMansion = 0;
		PlayGame(character.getName());
		break;
	case 2:
		system("CLS");
		ShowOffMansion = 0;
		ShowOffMansionStarted = false;
		ManCoruption();
		break;




	default:
		break;
	}

}

void Game::ManCoruption()
{
	string fileName = "Story.txt";
	vector<string> lines166To187 = loadSpecificLines(fileName, 166, 187);
	processLines(lines166To187);

	cout << "0: Quit" << endl;
	cout << "1: Restart" << endl;






	cout << endl << "Choice: ";
	while (!(cin >> manCorupt) || (manCorupt < 0 || manCorupt > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	manCoruptStarted = true;
	ShowOffMansionStarted = false;
	switch (manCorupt)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;




	default:
		break;
	}

}

void Game::PhanBattleAfter()
{
	string fileName = "Story.txt";
	vector<string> lines205To242 = loadSpecificLines(fileName, 205, 242);
	processLines(lines205To242);

	cout << "0: Quit" << endl;
	cout << "1: Restart" << endl;






	cout << endl << "Choice: ";
	while (!(cin >> phanBattleAfter) || (phanBattleAfter < 0 || phanBattleAfter > 1))
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	manCoruptStarted = false;
	phanBattleAfterStarted = true;
	switch (phanBattleAfter)
	{
	case 0:
		running = false;
		break;

	case 1:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		leftCreature = 0;
		PlayGame(character.getName());
		break;




	default:
		break;
	}

}





