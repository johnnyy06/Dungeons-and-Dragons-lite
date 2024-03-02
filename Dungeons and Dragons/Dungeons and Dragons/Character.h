#pragma once
#include "Race.h"
#include "Class.h"

class Character : public Race, public Class
{
private:
	std::string ch_name;
	int hitPoints;
	int strength;
	int dexterity;
	int intelligence;
public:
	Character() : ch_name("default"), hitPoints(100), strength(0),
		dexterity(0), intelligence(0) {}
	Character(const std::string& newName) : ch_name(newName), hitPoints(100), strength(0),
		dexterity(0), intelligence(0) {}

	Character(const Character& other);

	// setters
	void setCh_Name(const std::string& newName);
	void setHitPoints(const int newHP);
	void setC_name(const std::string& newName) { this->c_name = newName; }
	void setC_abilities(const std::vector <Ability>& newAbilities) { this->c_abilities = newAbilities; }
	void setC_attributes(const std::vector <Attribute>& newAttributes) { this->c_attributes = newAttributes; }
	void setR_name(const std::string& newName) { this->r_name = newName; }
	void setR_abilities(const std::vector <Ability>& newAbilities) { this->r_abilities = newAbilities; }
	void setR_attributes(const std::vector <Attribute>& newAttributes) { this->r_attributes = newAttributes; }
	
	// getters
	std::string getCh_name()const { return this->ch_name; }
	int getHitPoints()const { return this->hitPoints; }
	int getStrength()const { return this->strength; }
	int getDexterity()const { return this->dexterity; }
	int getIntelligence()const { return this->intelligence; }

	void addStrength(const int newStrength) { this->strength += newStrength; }
	void addDexterity(const int newDexterity) { this->dexterity += newDexterity; }
	void addIntelligence(const int newIntelligence) { this->intelligence += newIntelligence; }

	void takeDamage(const int damage) { this->hitPoints -= damage; }

	int abilityContribution(const int points);

	void castAbility(const std::string& ability) override; // poate o fac int pentru returnare daunelor

	friend std::ostream& operator <<(std::ostream& stream, Character& ch);
	
	~Character() {}
};


std::ostream& operator <<(std::ostream& stream, Character& ch);
