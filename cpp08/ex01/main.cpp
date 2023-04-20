#include "Span.h"

int main(void) {
  Span my_span(1);
  // TODO il ne addNumber que 9 fois !
  for (unsigned int i = 0; i < 11; i++) {
    try {
      my_span.addNumber(rand() % 100);
      my_span.longestSpan();
      std::cout << "number added !" << std::endl;
    } catch (std::exception &e) {
      std::cout << "oh: " << e.what() << std::endl;
    }
  }
}
