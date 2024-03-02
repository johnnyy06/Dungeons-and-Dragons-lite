#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Item.h"

class Room
{
private:
	std::string name;
	std::vector <Item> itemList;
	int itemCounter;
public:
	Room(const std::string& roomName, const std::string& filename);

	// setters
	void setItemCounter();

	//getters
	std::string getName()const { return this->name; }
	std::vector <Item> getItemList()const { return this->itemList; }
	int getItemCounter()const { return this->itemCounter; }

	friend std::ostream& operator <<(std::ostream& stream, const Room& room);

	~Room() {}
};

std::ostream& operator <<(std::ostream& stream, const Room& room);