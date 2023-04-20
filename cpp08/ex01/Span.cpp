#include "Span.h"

/* Constructeurs et destructeur */
Span::Span(unsigned int n) : _n(n) { }
Span::Span(const Span &other) : _n(other._n)
{
	for (unsigned int i = 0; i < other._numbers.size(); i++)
	{
		//_numbers.push_back(_numbers[i]); TODO iterator
	}
	// TODO
}
Span::~Span() {}

/* Operator overload */
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
	}
	return *this;
}

/* Methods */
void Span::addNumber(const unsigned int &number)
{
	if (_numbers.size() == _n)
	{
		throw ListFullExeption();
	}
	_numbers.push_back(number);
}

unsigned int Span::longestSpan() const
{
	if (_n <= 1 || _numbers.size() <= 1)
	{
		throw CannotFindSpanExeption();
	}
	unsigned int max = *max_element(_numbers.begin(), _numbers.end());
	unsigned int min = *min_element(_numbers.begin(), _numbers.end());

	return (max - min);

	// TODO calcul de distance s'il sont neg
	return (0);
}

unsigned int Span::shortestSpan() const
{
	if (_n <= 1 || _numbers.size() <= 1)
	{
		throw CannotFindSpanExeption();
	}
	std::list<unsigned int>::const_iterator it =
		max_element(_numbers.begin(), _numbers.end());
	return *it;
}

const char *Span::ListFullExeption::what() const throw()
{
	return "The list is full !";
}

const char *Span::CannotFindSpanExeption::what() const throw()
{
	return "Not enough value to find a span";
}
