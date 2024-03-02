#include"Race.h"

Race::Race(const Race& other)
{
	this->r_name = other.r_name;
	this->r_abilities = other.r_abilities;
	this->r_attributes = other.r_attributes;
}

void Race::setAbilities(const std::string& filename)
{
	std::ifstream file(filename);

	try
	{
		if (file.is_open() == false)
		{
			Logger log("Error! File could not be opened!\n");
			log.addToFille("LoggerFile.txt");

			throw CExceptions(101, "Error! File could not be opened!\n");
		}
		std::string newName;

		std::string strDamage;
		int newDamage = 0;

		std::string newRequired;

		std::string strCost;
		int newCost = 0;

		while (file.eof() == false)
		{
			file >> newName;

			file >> strDamage;
			newDamage = stoi(strDamage);

			file >> newRequired;

			file >> strCost;
			newCost = stoi(strCost);

			Ability temp(newName, newDamage, newRequired, newCost);

			this->r_abilities.push_back(temp);
		}

		file.close();
	}
	catch (CExceptions& e)
	{
		std::cerr << "Exception Code: " << e.getCode() << "\t Message: " << e.getMessage() << "\n";
	}
}

void Race::setAttributes(const std::string& filename)
{
	std::ifstream file(filename);

	try
	{
		if (file.is_open() == false) throw CExceptions(101, "Error! File could not be opened!\n");

		std::string newName;

		std::string strPoints;
		int newPoints = 0;

		while (file.eof() == false)
		{
			file >> newName;

			file >> strPoints;
			newPoints = stoi(strPoints);

			Attribute temp(newName, newPoints);

			this->r_attributes.push_back(temp);
		}

		file.close();
	}
	catch (CExceptions& e)
	{
		std::cerr << "Exception Code: " << e.getCode() << "\t Message: " << e.getMessage() << "\n";
	}
}
