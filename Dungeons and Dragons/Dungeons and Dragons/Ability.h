#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "CExceptions.h"

class Ability
{
private:
	std::string name;
	int damage;
	std::string required;
	int cost;
public:
	Ability(const std::string& newName, const int newDamage, const std::string& newRequired,
		const int newCost) : name(newName), damage(newDamage), required(newRequired),
		cost(newCost) {}

	std::string getName() const { return this->name; }
	int getDamage() const { return this->damage; }
	std::string getRequired() const { return this->required; }
	int getCost() const { return this->cost; }

	~Ability() {}
};

