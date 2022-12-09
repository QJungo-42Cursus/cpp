#include <iostream>

class Base {
public:
  virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

/// Elle crée aléatoirement une instance de A, B ou C et la retourne en tant que
/// pointeur sur Base. Utilisez ce que vous souhaitez pour l’implémentation du
/// choix aléatoire
Base *generate(void) {
  int choice = rand() % 3;
  if (choice == 0)
    return (new A());
  else if (choice == 1)
    return (new B());
  else
    return (new C());
}

/// Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".
void identify(Base *p) {
  Base *identifier;

  identifier = dynamic_cast<A *>(p);
  if (identifier != NULL) {
    std::cout << "A" << std::endl;
    return;
  }
  identifier = dynamic_cast<B *>(p);
  if (identifier != NULL) {
    std::cout << "B" << std::endl;
    return;
  }
  identifier = dynamic_cast<C *>(p);
  if (identifier != NULL) {
    std::cout << "C" << std::endl;
    return;
  }
  std::cout << "aucun des types" << std::endl;
}

/// Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".
/// Utiliser un pointeur dans cette fonction est interdit.
void identify(Base &p) {
  try {
    Base &identify = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::bad_cast e) {
  }
  try {
    Base &identify = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::bad_cast e) {
  }
  try {
    Base &identify = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::bad_cast e) {
  }
  std::cout << "aucun des types" << std::endl;
}

int main() {
  for (int i = 0; i < 10; i++) {
    std::cout << "test " << i << std::endl;
    Base *randow = generate();
    identify(randow);
    identify(*randow);
    delete randow;
    std::cout << std::endl;
  }
}
