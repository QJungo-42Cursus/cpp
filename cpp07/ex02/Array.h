#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <typename T> class Array {
public:
  /* Constructors and Destructors */
  Array() {
    _size = 0;
    _array = NULL;
  }

  Array(unsigned int size) {
    _size = size;
    _array = new T[size];
  }

  Array(Array const &src) {
    _size = src._size;
    _array = new T[src._size];
    for (int i = 0; i < _size; i++) {
      _array[i] = src._array[i];
    }
  }

  ~Array() {
    if (_array != NULL) {
      delete[] _array;
    }
  }

  /* Operators overload */
  Array &operator=(Array const &rhs) {
    if (_array != NULL) {
      delete[] _array;
    }
    _size = rhs._size;
    _array = new T[rhs._size];
    for (int i = 0; i < _size; i++) {
      _array[i] = rhs._array[i];
    }
    return (*this);
  }

  T &operator[](const unsigned int i) {
    /// vu qu'il est caste en unsigned int, s'il est negatif, il reviendra a un
    /// chiffre positif !
    if (i >= _size) {
      throw OutOfRangeException();
    }
    return (_array[i]);
  }

  /* Getters */
  int size() const { return (_size); }

  /* Errors */
  struct OutOfRangeException : public std::exception {
    const char *what() const throw() { return ("Out of range of the array !"); }
  };

private:
  unsigned int _size;
  T *_array;
};

#endif /* ARRAY_H */
