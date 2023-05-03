#ifndef RPN_H
#define RPN_H

#include <string>
#include <stack>

class RPN
{
public:
	explicit RPN(const std::string &str);

	~RPN();

private:
	RPN();

	RPN &operator=(const RPN &rnp);

	RPN(const RPN &rnp);

	std::stack<int> _stack;
};

#endif
