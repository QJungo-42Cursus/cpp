#include "BitcoinExchange.h"
#include <fstream>
#include <sstream>
#include <limits>

int run(char *filename)
{
	BitcoinExchange bitcoinExchange;
	std::fstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cout << "Error: invalid file format" << std::endl;
		return 1;
	}
	while (std::getline(file, line))
	{
		if (line.size() < 14)
		{
			std::cout << "Error: bad format => " << line << std::endl;
			continue;
		}
		Time time(line.substr(0, 10));
		float price;
		float result;
		try
		{
			std::size_t pos = line.find(" | ");
			if (pos == std::string::npos)
				throw std::runtime_error("invalid file format: " + line);
			std::stringstream(line.substr(pos + 2)) >> price;
			if (price < 0)
				throw std::runtime_error("not a positive number");
			if (price > 1000)
				throw std::runtime_error("too big number");
			result = bitcoinExchange.getValFromTime(time, price);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			continue;
		}
		std::cout << time << " => " << price << " = " << result << std::endl;
	}
	file.close();
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	return run(argv[1]);
}
