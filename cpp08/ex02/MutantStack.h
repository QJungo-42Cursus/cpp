#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  /* TODO la version de ft_containers
  MutantStack<T>& operator=(const MutantStack<T>& rhs)
  {
          this->c = rhs.c;
          return *this;
  }
  ~MutantStack() {}

  typedef typename ft::stack<T>::container_type::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  */
  /* Constructors and Destructor */
  MutantStack() {}
  MutantStack(const MutantStack &other) {}
  virtual ~MutantStack() {}

  /* Operator overload */
  // virtual MutantStack &operator=(const MutantStack &rhs) {}

  /* Element access */
  virtual const T &top() const { return _container.back(); }

  /* Capacity */
  virtual const bool empty() const { return _container.empty(); }
  virtual const int size() const { return _container.size(); }

  /* Modifiers */
  virtual void push(const T &new_element) { _container.push_back(new_element); }
  virtual void pop() { _container.pop_back(); }

  /* Iterator class */
  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    typename std::deque<T>::iterator _it;
    std::deque<T> &_containerRef;
    iterator() { std::cout << "default called !" << std::endl; }

  public:
    iterator(std::deque<T> &containerRef, bool is_end)
        : _containerRef(containerRef) {
      if (!is_end) {
        _it = _containerRef.begin();
      } else {
        // TODO la valeur de deferencement de end() va automatiquement etre 0.
        // donc s'il y a un 0 dans la list...
        _it = _containerRef.end();
      }
    }

    iterator &operator=(const iterator &rhs) {
      _containerRef = rhs._containerRef;
      _it = rhs._it;
      return *this;
    }

    iterator &operator--() {
      _it--;
      return *this;
    }

    // TODO est-ce que ca morche ?
    iterator &operator++(int) {
      _it++;
      return *this;
    }

    iterator &operator++() {
      _it++;
      return *this;
    }

    bool operator==(const iterator &other) const { return *this == other; }
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
