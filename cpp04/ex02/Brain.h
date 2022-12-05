#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
public:
  Brain();
  ~Brain();
  void think();
  std::string ideas[100];
};

#endif /* BRAIN_H */
