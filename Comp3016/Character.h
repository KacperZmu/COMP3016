#pragma once
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;
class Character
{
public:
	Character();
	virtual ~Character();


	//Functions
	void init(const string name, const string race);
	void printPlayeStats() const;
	void levelUp();
	void takeDamage(int damage);
	void ResetHealth();

	
	inline const string& getName() const { return this->name; }
	inline const string& getRace() const { return this->race; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getHPMax() const { return this->hpMax; }
	inline const int& getMana() const { return this->mana; }
	inline const int& getManaMax() const { return this->manaMax; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	

private:
	double xPos;
	double yPos;

	string name;
	string race;
	int level;
	int exp;
	int expNext;
	int hp;
	int hpMax;
	int mana;
	int manaMax;
	int damageMin;
	int damageMax;
	int defence;
};

