#include <iostream>
#include "RPN.h"

bool is_a_invalid_char(const std::string &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (std::string("+-*/0123456789 ").find(*it) == std::string::npos)
			return true;
	return false;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	if (is_a_invalid_char(argv[1]))
	{
		std::cout << "Invalid expression" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
