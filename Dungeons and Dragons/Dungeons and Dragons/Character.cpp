#include "Character.h"

Character::Character(const Character& other)
{
	this->ch_name = other.ch_name;
	this->hitPoints = other.hitPoints;
	this->strength = other.strength;
	this->dexterity = other.dexterity;
	this->intelligence = other.intelligence;

	this->c_name = other.c_name;
	this->c_abilities = other.c_abilities;
	this->c_attributes = other.c_attributes;

	this->r_name = other.r_name;
	this->r_abilities = other.r_abilities;
	this->c_attributes = other.r_attributes;
}

void Character::setCh_Name(const std::string& newName)
{
	this->ch_name = newName;
}

void Character::setHitPoints(const int newHP)
{
	this->hitPoints = newHP;
}

int Character::abilityContribution(const int points)
{
	if (points == 1) return -5;

	if (points == 2 || points == 3) return -4;

	if (points == 4 || points == 5) return -3;

	if (points == 6 || points == 7) return -2;

	if (points == 8 || points == 9) return -1;

	if (points == 10 || points == 11) return 0;

	if (points == 12 || points == 13) return 1;

	if (points == 14 || points == 15) return 2;

	if (points == 16 || points == 17) return 3;

	if (points == 18 || points == 19) return 4;

	if (points == 20 || points == 21) return 5;

	if (points == 22 || points == 23) return 6;

	if (points == 24 || points == 25) return 7;

	if (points == 26 || points == 27) return 8;

	if (points == 28 || points == 29) return 9;

	if (points == 30) return 10;
}

void Character::castAbility(const std::string& ability)
{
	for (const auto& iter : this->c_abilities)
	{
		if (ability == iter.getName())
		{
			std::cout << "\t" << "You have casted " << iter.getName() << "\n";
		}
	}
}

std::ostream& operator<<(std::ostream& stream, Character& ch)
{
	stream << "\tYour character: " << ch.ch_name << " is " << ch.r_name << " and " << ch.c_name << "\n";
	stream << "\tStrength: " << ch.strength << "   Dexterity: " << ch.dexterity << "   Intelligence: " << ch.intelligence << "\n";
	
	stream << "\tAbilities:\n";
	for (auto& i : ch.r_abilities)
	{
		stream << "\t" << i.getName() << " " << i.getDamage() << "\n";
	}

	for (auto& i : ch.c_abilities)
	{
		stream << "\t" << i.getName() << " " << i.getDamage() << "\n";
	}


	return stream;
}
