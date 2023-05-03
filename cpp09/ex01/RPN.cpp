#include <iostream>
#include "RPN.h"
#include <sstream>

RPN::RPN(const std::string &str)
{
	std::string::const_iterator it = str.begin();
	std::string tmp;

	while (true)
	{
		if (*it == ' ' || it == str.end())
		{
			if (!tmp.empty())
			{
				if (tmp.size() != 1)
					throw std::runtime_error("Invalid expression");
				char c = tmp[0];
				if (std::string("+-*/").find(c) != std::string::npos)
				{
					int right = _stack.top();
					_stack.pop();
					int left = _stack.top();
					_stack.pop();
					if (c == '+')
						_stack.push(left + right);
					else if (c == '-')
						_stack.push(left - right);
					else if (c == '*')
						_stack.push(left * right);
					else if (c == '/')
						_stack.push(left / right);
				}
				else
					_stack.push(c - '0');
			}
			tmp.clear();
		}
		else
			tmp += *it;
		if (it == str.end())
			break;
		++it;
	}
	if (_stack.size() != 1) throw std::runtime_error("Invalid expression, too many operands");
	std::cout << _stack.top() << std::endl;
}

RPN::RPN()
{}

RPN::RPN(const RPN &rnp)
{
	if (this != &rnp)
	{
		_stack = rnp._stack;
	}
}

RPN &RPN::operator=(const RPN &rnp)
{
	if (this != &rnp)
	{
		_stack = rnp._stack;
	}
	return *this;
}

RPN::~RPN()
{}