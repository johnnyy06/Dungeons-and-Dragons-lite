#pragma once
#include <iostream>
#include <string>

class Attribute
{
private:
	std::string name;
	int points;
public:
	Attribute(const std::string newName, const int newPoints) : name(newName), points(newPoints) {}

	std::string getName() const { return this->name; }
	int getPoints() const { return this->points; }

	~Attribute() {}
};

