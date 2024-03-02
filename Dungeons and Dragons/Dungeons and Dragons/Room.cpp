#include "Room.h"
#include <fstream>

Room::Room(const std::string& roomName, const std::string& filename) : itemCounter(0)
{
	this->name = roomName;

	std::ifstream file(filename);

	std::string itemName;
	std::string whereTo;
	std::string ability;
	std::string strPoints;
	int  points = 0;
	std::string abilityRequired;
	std::string strCost;
	int cost = 0;

	while (file.eof() == false)
	{
		file >> itemName;

		Item item(itemName, "", 0);

		if (itemName == "Portal" || itemName == "Door")
		{
			file >> whereTo;
			file >> abilityRequired;
			file >> strCost;
			cost = std::stoi(strCost);

			item.setWhatRequired(abilityRequired);
			item.setAmountRequired(cost);
			item.setWhereTo(whereTo);
		}
		else
		{
			file >> ability;
			file >> strPoints;
			points = std::stoi(strPoints);
			file >> abilityRequired;
			file >> strCost;
			cost = std::stoi(strCost);

			item.setWhatRequired(abilityRequired);
			item.setAmountRequired(cost);
			item.setWhatGives(ability);
			item.setAmountGiven(points);
		}
		this->itemList.push_back(item);
	}
	file.close();
}

void Room::setItemCounter()
{
	for (auto& i : this->itemList)
	{
		this->itemCounter++;
	}
}

std::ostream& operator<<(std::ostream& stream, const Room& room)
{
	stream << "\tYou are in " << room.name << "\n";
	stream << "\tActions available: \n";
	
	int actionCounter = 1;

	for (const auto& i : room.itemList)
	{
		if (i.getName() == "Book")
			stream << "\t" << actionCounter << ") Read <" << i.getName() << "> and get " <<
			i.getAmountGiven() << " " << i.getWhatGives() << " - roll " << i.getAmountRequired() <<
			" " << i.getWhatRequired() << "\n";
		else
			stream << "\t" << actionCounter << ") Open <" << i.getName() << "> and go to " <<
			i.getWhereTo() << " - roll " << i.getAmountRequired() << " " << i.getWhatRequired() << "\n";

		actionCounter++;
	}

	return stream;
}
