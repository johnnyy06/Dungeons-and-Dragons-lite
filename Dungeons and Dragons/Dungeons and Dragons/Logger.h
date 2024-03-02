#pragma once
#include <iostream>
#include <fstream>

class Logger
{
private:
	std::string msg;
public:
	Logger(const std::string& newMsg) : msg(newMsg) {}

	void addToFille(const std::string& filename);
};

