#pragma once
#include <iostream>
#include <vector>
#include "Ability.h"
#include "Attribute.h"
#include "ICharacter.h"
#include "Logger.h"

class Class : virtual public ICharacter
{
protected:
	std::string c_name;
	std::vector <Ability> c_abilities;
	std::vector <Attribute> c_attributes;
public:
	Class() : c_name("Default") {}
	Class(const std::string& newName) : c_name(newName) {}

	Class(const Class& other);

	// setters
	void setAbilities(const std::string& filename);
	void setAttributes(const std::string& filename);

	// getters
	std::string getC_name()const { return this->c_name; }
	std::vector <Ability> getC_abilities()const { return this->c_abilities; }
	std::vector <Attribute> getC_attributes()const { return this->c_attributes; }

	void castAbility(const std::string& ability) { std::cout << this->c_name << " casted an ability!\n\n"; }

	virtual ~Class() {}
};

