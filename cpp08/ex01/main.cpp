#include "Span.h"

int main()
{
  Span my_span(10);
  for (unsigned int i = 0; i < 15; i++)
  {
    try
    {
      unsigned int n = rand() % 102;
      std::cout << "adding number: " << n << std::endl;
      my_span.addNumber(n);
      std::cout << "shortest span: " << my_span.shortestSpan() << std::endl;
      std::cout << "longest span: " << my_span.longestSpan() << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "oh: " << e.what() << std::endl;
    }
  }
}
