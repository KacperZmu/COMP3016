#include "Game.h"
#include <random>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


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

	cout << endl << "Choice: ";
	cin >> choice;
	cout << endl;

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
	string fileName = "Story.txt";
	vector<string> lines1To30 = loadSpecificLines(fileName, 1, 30);
	processLines(lines1To30);
	

	cout << "0: Quit" << endl; 
	cout << "1: Character Info" << endl; 
	cout << "2: Head Towards the Mansion" << endl;
	cout << "3: Approach the Creature..." << endl; 
	cout << "4: Time for the never ending story?" << endl << endl;   
	

	
	cout << endl << "Choice: ";
	cin >> playerChoice;
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
	cin >> leftCreature;
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
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 20);
		int randomNumber = dis(gen);
		if (randomNumber > 8) {
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
	cout << "1: Run Away" << endl;
	cout << "2: Attack the creature" << endl;





	cout << endl << "Choice: ";
	cin >> killedCreature;
	cout << endl;
	leftCreatureStarted = true;
	playStarted = false;
	switch (killedCreature)
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
	cin >> DeathScr;
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
	cout << "1: Character Info" << endl;
	cout << "2: Head Back" << endl;
	cout << "3: Show off your physical prowess" << endl;
	cout << "4: Attack the creature" << endl;
	cout << "5: Try to reason" << endl;
	


	
	cout << endl << "Choice: ";
	cin >> moveMansion;
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
		character.printPlayeStats();
		break;
	case 2:
		system("CLS");
		playStarted = true;
		playerChoice = 0;
		moveMansion = 0;
		PlayGame(character.getName());
		break;



	default:
		break;
	}

}