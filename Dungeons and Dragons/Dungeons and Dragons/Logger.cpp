#include "Logger.h"

void Logger::addToFille(const std::string& filename)
{
	std::ofstream file(filename, std::ios::app);

        file << this->msg <<"\n";

        file.close();
}
