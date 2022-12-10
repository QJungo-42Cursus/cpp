#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <iterator>
#include <list>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  /* Constructors and Destructor */
  MutantStack() {}
  MutantStack(const MutantStack &other) {}
  ~MutantStack() {}

  /* Operator overload */
  MutantStack &operator=(const MutantStack &rhs) {}

  /* Element access */
  const T &top() const {}

  /* Capacity */
  const bool empty() const {}
  const int size() const {}

  /* Modifiers */
  void push(const T &new_element) {}
  void pop() {}
  // void swap(?) {} // C++11
  // void emplace(?) {} // C++11
  /* TODO : font parti de list de base... ?
  void back() {}
  void push_back(const T &new_element) {}
  void pop_back() {}
  */

  class iterator : public std::forward_iterator_tag {};

private:
  std::list<T> _container;
};

#endif /* MUTANTSTACK_H */
