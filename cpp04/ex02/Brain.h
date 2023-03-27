#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
public:
	// Constructors
  Brain();
  virtual ~Brain();
  Brain(const Brain &other);

  /* Operator Overload */
  Brain &operator=(const Brain &other);

  // attributes
  std::string ideas[100];
};

#endif /* BRAIN_H */
