#include "Character.h"

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = "";
	this->race = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->mana = 0;
	this->manaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
}

Character ::~Character()
{

}

void Character::init(const string name, const string race)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->race = race;
	this->level = level;
	this->exp = 0;
	this->expNext = 100;
	this->hp = 100;
	this->hpMax = 100;
	this->mana = 50;
	this->manaMax = 50;
	this->damageMin = 4;
	this->damageMax = 12;
	this->defence = 2;
}

void Character::printPlayeStats() const
{
	cout << "= Character Sheet =" << endl << endl;
	cout << "= Name: " << this->name << endl;
	cout << "= Race: " << this->race << endl;
	cout << "= Level: " << this->level << endl;
	cout << "= Exp to next level: " << this->expNext << endl;
	cout << "= Health: " << this->hp << " / " << this->hpMax << endl;
	cout << "= Mana: " << this->mana << " / " << this->manaMax << endl;
	cout << "= Min/Max Damage: " << this->damageMin << " - " << this->damageMax << endl;
	cout << "= Defence: " << this->defence << endl << endl;
	
}

void Character::levelUp()
{
	while (exp >= expNext)
	{
		exp -= expNext;
		level++;
		damageMax = damageMax + 2;
		damageMin = damageMin + 2;
		hpMax = hpMax + 10;
		hp = hp + 10;
		manaMax = manaMax + 10;
		mana = mana + 10;
		defence = defence + 3;
		this->expNext = 100;
	}
	
	
	

}
