#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl {
public:
  Harl();
  static void complain(std::string level);

private:
  void debug(void) const;
  void info(void) const;
  void warning(void) const;
  void error(void) const;
  void (Harl::*complainFunc[4])(void) const;
  const std::string levels[4] = {"debug", "info", "warning", "error"};
  enum Level { DEBUG, INFO, WARNING, ERROR };
};

#endif /* HARL_H */
