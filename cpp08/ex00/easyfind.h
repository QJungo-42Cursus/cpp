#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>

struct NotFoundException : public std::exception
{
  virtual const char *what() const throw();
};

template <typename T>
int easyfind(T &container, int i)
{
  typename T::const_iterator it = std::find(container.begin(), container.end(), i);
  if (it == container.end())
  {
    throw NotFoundException();
  }
  return *it;
}

#endif /* EASYFIND_H */
