#pragma once
#include <string>

class ICharacter
{
public:
	virtual void castAbility(const std::string& ability) = 0;
};