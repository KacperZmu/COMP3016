#include "Game.h"
#include <random>
using namespace std;

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
	cout << "Welcome to Murkwood Sanctuary " << playerName <<"! \nDon't let the name fool you. It is far from a sanctuary " << endl << endl; 
	cout << "MurkWood is a realm cloaked in an ethereal mist \nthat shrouds the ancient tree in an otherworldly haze. " << endl;
	cout << "As you step cautiously through the forest, the \nair is thick with a mysterious energy, " << endl;
	cout << "and the soft crunch of fallen leaves beneath \nyour feet echoes through the silence. You hear no other life around you.  " << endl;
	cout << "The twisted branches above form an intricate \ncanopy that filters the pale moolight, casting an earie glow  " << endl;
	cout << "on the damp forest floor.  " << endl << endl; 
	cout << "In the distance lies an imposing mansion, its' \ndark silhouette imposing against the fog laden backdrop.  " << endl;
	cout << "A palpable aura of corruption emanates from \nits' walls, whispering tales of secrets, long buried within.  " << endl << endl; 
	cout << "To the Left, a winding stretches endlessly \ninto the unknown, with each visible bend revealing more mysteries than the last.  " << endl;
	cout << "The air is filled with anticipation as you \nconsider what lies beyond the seemingly infinite trail.  " << endl << endl; 
	cout << "To the right, a creature of unknown origin \nlurks in the shadows. Its' eyes gleam with an otherworldly intelligence,  " << endl;
	cout << "and the air around it crackles with a sense of \ndanger. you take a deap breath, the crisp cold air burns inside your lungs, " << endl;
	cout << "your nose is filled with the scent of death. \nShould you app, be wary, for this mysterious being mat hold the secrets woven\ninto the very fabric of Murkwood Sanctuary.  " << endl <<endl;
	cout << "The forest beckons,Young " << playerName << ". Will you explore the \ncurrupt mansion halls? brave the unending path" << endl;
	cout << "or face the enigmatic creature that guards the secrets of this mystic realm?   " << endl << endl;
	cout << "The choice  " << endl;
	cout << "Is yours  " << endl << endl; 
	

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
	cout << "As you cautiously veer right, your gaze fixates on the mysterious" << endl;
	cout << "creature lurking in the shadows. The air thickens with an eerie" << endl;
	cout << "tension, and an unnatural stillness envelopes the space around you. " << endl;
	cout << "The creature, a silhouette of twisted forms and gleaming eyes " << endl;
	cout << "emerges slowly from the darkness. " << endl << endl; 
	cout << "A low, gutteral growl resonates through the air, sending shivers " << endl;
	cout << "down your spine. The creatures' eyes lock onto yours. " << endl;
	cout << "Its' features obscured by the foggy veil. Inseed whispers " << endl;
	cout << "seem to emanate from its presence, weaving a chilling tapestry of " << endl;
	cout << "unknown horrors. " << endl << endl; 
	cout << "Will you face the ominous being, risking the unknown danger " << endl;
	cout << "it may pose, or wisely choose to retreat. " << endl;
	cout << "The choice is yours, and the consequences may haunt your every step " << endl;
	cout << "... " << endl << endl; 
	


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
	cout << "You.. Killed IT" << endl << endl;
	cout << "As the creatures life fades, an ominous stillness settles upon" << endl;
	cout << "the sanctuary. With its last breath the creatures thoughts echo" << endl;
	cout << "through your mind- a haunting revalation that it was a pacifist," << endl;
	cout << "a guardian sworn to protect the very forest it inhabited." << endl << endl;
	cout << "The world around you darkens, as if the shadows themselves" << endl;
	cout << "mourn the loss of their guardian. Whispers and distant screams" << endl;
	cout << "permeate the air, carrying with them the weight of a forest left vulnerable." << endl;
	cout << "The once mutated cries of unseen creatures now crescendo into a canopy of" << endl;
	cout << "despair." << endl << endl;
	cout << "You stand alone, the unintended executioner of a silent protector." << endl;
	cout << "the responsibility to safeguard the sanctuary now falls upon your shoulders." << endl;
	cout << "Will you honour the fallen guardians last wishes, and slowly turn into" << endl;
	cout << "creature itself? or will you go on, after all, youre just a " <<playerRace << endl << endl;



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
	cout << "You...Died" << endl;
	



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
	cout << "As you cautiously approach the mansion, the fog seems to thicken," << endl;
	cout << "swirling around the looming structure like ghostly tendrils." << endl;
	cout << "The air becomes charged with an unsetlling energy, with distant howls" << endl;
	cout << "of unkown creatures you've never heard before, ehcoing through the" << endl;
	cout << "twisted corridors of the forrest" << endl << endl; 
	cout << "The mansions grand entrance stands before you, its' once" << endl;
	cout << "opulent facade now marred by time, and an ominous air of" << endl;
	cout << "malevolance brushes against you. As you step forth towards the gate," << endl;
	cout << "a creature resembling a phantom apears before you" << endl << endl;
	cout << "'Be gone foul being!' the creature squeals with a heavy rasp" << endl;
	cout << "'Your kind doesn't belong here. Tonight you will take your last breath!'" << endl << endl;

	
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