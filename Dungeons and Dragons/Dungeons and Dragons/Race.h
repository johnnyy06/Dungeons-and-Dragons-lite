#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Ability.h"
#include "Attribute.h"
#include "ICharacter.h"
#include "Logger.h"

class Race : virtual public ICharacter
{
protected:
	std::string r_name;
	std::vector <Ability> r_abilities;
	std::vector <Attribute> r_attributes;
public:
	Race() : r_name("Default") {}
	Race(const std::string& newName) : r_name(newName) {}

	Race(const Race& other);
	
	void setAbilities(const std::string& filename); // read the abilities from file and store them into race
	void setAttributes(const std::string& filename); // read the attributes from file and store them into race

	// getters
	std::string getR_name()const { return this->r_name; }
	std::vector <Ability> getR_abilities()const { return this->r_abilities; }
	std::vector <Attribute> getR_attributes()const { return this->r_attributes; }

	void castAbility(const std::string& ability) { std::cout << this->r_name << " casted an ability!\n\n"; }

	virtual ~Race() {}
};