#pragma once
#include <iostream>
#include <string>

class Item
{
private:
	std::string name; // numele obiectului 
	std::string whatRequired; // ce abilitate e necesara pentru a folosi obiecul
	int amountRequired;	// cate puncte in abilitate sunt necesare pentru a folosi obiectul
	std::string whereTo; // unde te duce obiectul (doar daca e usa sau portal)
	std::string whatGives; // daca e carte acest string va spune ce abilitate primesti
	int amountGiven; // acesta va spune cate puncte primesti in abilitatea respectiva

public:
	Item(const std::string& newName, const std::string& required, const int amount)
		: name(newName), whatRequired(required), amountRequired(amount), 
		whereTo("This item can't get you anywhere!"), whatGives("Nothing"),
		amountGiven(0) {}

	// setters
	void setWhatRequired(const std::string& requiredAbility) { this->whatRequired = requiredAbility;};
	void setAmountRequired(const int amount) { this->amountRequired = amount; };
	void setWhereTo(const std::string& location);
	void setWhatGives(const std::string& ability);
	void setAmountGiven(const int numberOfAbilityPoints);

	//getters
	std::string getName()const { return this->name; }
	std::string getWhatRequired()const { return this->whatRequired; }
	int getAmountRequired()const { return this->amountRequired; }
	std::string getWhereTo()const { return this->whereTo; }
	std::string getWhatGives()const { return this->whatGives; }
	int getAmountGiven()const { return this->amountGiven; }

	~Item() {}
};

