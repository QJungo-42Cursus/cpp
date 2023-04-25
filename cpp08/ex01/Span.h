#ifndef SPAN_H
#define SPAN_H
#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
public:
  /* Constructeurs et destructeur */
  Span(unsigned int n);
  Span(const Span &other);
  ~Span();

  /* Operator overload */
  Span &operator=(const Span &rhs);

  /* Methods */
  void addNumber(const unsigned int &number);
  unsigned int longestSpan() const;
  unsigned int shortestSpan() const;

  /* Exception */
  struct ListFullExeption : public std::exception
  {
    virtual const char *what() const throw();
  };

  struct CannotFindSpanExeption : public std::exception
  {
    virtual const char *what() const throw();
  };

private:
  const unsigned int _n;
  std::vector<unsigned int> _numbers;
  Span();
};

#endif /* SPAN_H */
