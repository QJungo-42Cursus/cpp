#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl {
public:
  static void complain(std::string level);
  static void setLevel(std::string level);
  enum Level : char { DEBUG, INFO, WARNING, ERROR };

private:
  /* Attributes */
  static Level _level;

  /* Methods */
  void debug(void) const;
  void info(void) const;
  void warning(void) const;
  void error(void) const;
  void (Harl::*complainFunc[4])(void) const = {&Harl::debug, &Harl::info,
                                               &Harl::warning, &Harl::error};
  const static std::string levels[4];

  Harl() {}
};

#endif /* HARL_H */
