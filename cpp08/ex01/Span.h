#ifndef SPAN_H
#define SPAN_H
#include <algorithm>
#include <iostream>
#include <list>

class Span {
public:
  /* Constructeurs et destructeur */
  Span(unsigned int n) : _n(n) { _numbers = {}; }
  Span(const Span &other) : _n(other._n) {
    for (int i = 0; i < other._numbers.size(); i++) {
      //_numbers.push_back(_numbers[i]); TODO iterator
    }
    // TODO
  }
  ~Span() {}

  /* Operator overload */
  Span &operator=(const Span &rhs) {
    // TODO
    return *this;
  }

  /* Methods */
  void addNumber(const int &number) {
    if (_numbers.size() == _n) {
      throw ListFullExeption();
    }
    _numbers.push_back(number);
  }

  int longestSpan() const {
    if (_n <= 1 || _numbers.size() <= 1) {
      throw CannotFindSpanExeption();
    }
    int max = *max_element(_numbers.begin(), _numbers.end());
    int min = *min_element(_numbers.begin(), _numbers.end());

    // TODO calcul de distance s'il sont neg
    return (0);
  }

  int shortestSpan() const {
    if (_n <= 1 || _numbers.size() <= 1) {
      throw CannotFindSpanExeption();
    }
    std::list<int>::const_iterator it =
        max_element(_numbers.begin(), _numbers.end());
    return *it;
  }

  /* Exception */
  struct ListFullExeption : public std::exception {
    virtual const char *what() const throw() { return "The list is full !"; };
  };

  struct CannotFindSpanExeption : public std::exception {
    virtual const char *what() const throw() {
      return "Not enough value to find a span";
    };
  };

private:
  const unsigned int _n;
  std::list<int> _numbers;
  Span();
};

#endif /* SPAN_H */
