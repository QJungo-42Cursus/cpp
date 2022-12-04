#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl {
public:
  Harl();
  ~Harl();
  static void complain(std::string level);
  void (Harl::*complainFunc[4])(void);

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  std::string levels[4] = {"debug", "info", "warning", "error"};
  enum Level { DEBUG, INFO, WARNING, ERROR };
};

#endif /* HARL_H */
