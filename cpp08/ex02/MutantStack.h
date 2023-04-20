#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
  /* Constructors and Destructor */
  MutantStack() {}
  MutantStack(const MutantStack &other) { _container = other._container; }
  MutantStack &operator=(const MutantStack &rhs) { _container = rhs._container; }
  virtual ~MutantStack() {}

  /* Element access */
  virtual const T &top() const { return _container.back(); }

  /* Capacity */
  virtual bool empty() const { return _container.empty(); }
  virtual int size() const { return _container.size(); }

  /* Modifiers */
  virtual void push(const T &new_element) { _container.push_back(new_element); }
  virtual void pop() { _container.pop_back(); }

  /* Iterator class */
  class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
  {
  private:
    typename std::deque<T>::iterator _it;
    std::deque<T> &_containerRef;
    iterator() { std::cout << "default called !" << std::endl; }

  public:
    iterator(std::deque<T> &containerRef, bool is_end)
        : _containerRef(containerRef)
    {
      if (!is_end)
      {
        _it = _containerRef.begin();
      }
      else
      {
        _it = _containerRef.end();
      }
    }

    iterator &operator=(const iterator &rhs)
    {
      _containerRef = rhs._containerRef;
      _it = rhs._it;
      return *this;
    }

    iterator &operator--()
    {
      if (_it == _containerRef.begin())
        return *this;
      _it--;
      return *this;
    }

    iterator &operator++(int)
    {
      if (_it == _containerRef.end())
        return *this;
      _it++;
      return *this;
    }

    iterator &operator++()
    {
      if (_it == _containerRef.end())
        return *this;
      _it++;
      return *this;
    }

    bool operator==(const iterator &other) const { return _it == other._it; }
    bool operator!=(const iterator &other) const { return !(*this == other); }
    T operator*() const { return *_it; }
  };

  /* Iterator method */
  iterator begin() { return iterator(_container, false); }
  iterator end() { return iterator(_container, true); }

private:
  std::deque<T> _container;
};

#endif /* MUTANTSTACK_H */
