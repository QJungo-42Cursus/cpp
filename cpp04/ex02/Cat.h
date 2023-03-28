#ifndef CAT_H
#define CAT_H
#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
public:
  /* Constructor and Destructor */
  Cat();
  Cat(const Cat &other);
  virtual ~Cat();

  /* Operator Overloads */
  Cat &operator=(const Cat &other);

  /* Methods override */
  void makeSound() const;

private:
  Brain *_brain;
};

#endif /* CAT_H */
