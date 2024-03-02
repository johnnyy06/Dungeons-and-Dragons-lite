#include "Item.h"
#include "CExceptions.h"

void Item::setWhereTo(const std::string& location)
{
	try
	{
		if (this->name != "Door" && this->name != "Portal")
			throw CExceptions(1, "This is neither a door nor a portal!\n");

		this->whereTo = location;
	}
	catch (const CExceptions& e)
	{
		std::cerr << "Error code: " << e.getCode() << "!\tError message: " << e.getMessage();
	}
}

void Item::setWhatGives(const std::string& ability)
{
	try
	{
		if (this->name != "Book")
			throw CExceptions(2, "This is not a book!\n");

		this->whatGives = ability;
	}
	catch (const CExceptions& e)
	{
		std::cerr << "Error code: " << e.getCode() << "!\tError message: " << e.getMessage();
	}
}

void Item::setAmountGiven(const int numberOfAbilityPoints)
{
	try
	{
		if (this->name != "Book")
			throw CExceptions(2, "This is not a book!\n");

		this->amountGiven = numberOfAbilityPoints;
	}
	catch (const CExceptions& e)
	{
		std::cerr << "Error code: " << e.getCode() << "!\tError message: " << e.getMessage();
	}
}
