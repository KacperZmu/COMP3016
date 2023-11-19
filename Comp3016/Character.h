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

	// For player Stats
	inline const string& getName() const { return this->name; }
	inline const string& getRace() const { return this->race; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getHPMax() const { return this->hpMax; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	

private:
	

	string name;
	string race;
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	
};

