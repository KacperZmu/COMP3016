#include "Character.h"

Character::Character()
{
	this->name = "";
	this->race = "";
	this->level = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	
}

Character ::~Character()
{

}

void Character::init(const string name, const string race)
{
	

	this->name = name;
	this->race = race;
	this->level = level;
	this->hp = 100;
	this->hpMax = 100;
	this->damageMin = 4;
	this->damageMax = 12;
	
}

void Character::printPlayeStats() const
{
	cout << "= Character Sheet =" << endl << endl;
	cout << "= Name: " << this->name << endl;
	cout << "= Race: " << this->race << endl;
	cout << "= Level: " << this->level << endl;
	cout << "= Health: " << this->hp << " / " << this->hpMax << endl;
	cout << "= Min/Max Damage: " << this->damageMin << " - " << this->damageMax << endl << endl << endl << endl;
	
	
}

void Character::levelUp()
{
		level++;
		damageMax = damageMax + 2;
		damageMin = damageMin + 2;
		hpMax = hpMax + 10;
		hp = hp + 10;
		
	
	
	
	

}

void Character::takeDamage(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}

}

void Character::ResetHealth()
{
	hp = hpMax;
}

