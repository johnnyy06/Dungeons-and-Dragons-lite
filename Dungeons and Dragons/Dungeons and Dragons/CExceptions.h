#pragma once
#include <iostream>


class CExceptions
{
private:
	int code;
	std::string message;
public:
	CExceptions(int newCode, std::string newMessage) : code(newCode), message(newMessage) {}

	int getCode() const { return this->code; }
	std::string getMessage() const { return this->message; }
};

