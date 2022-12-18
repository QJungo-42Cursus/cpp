#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

// Permet de convertir un entier en string
template <typename T> static std::string to_string(const T &value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

// besoin de redeclare les variables static dans le .cpp
// (sinon undefined reference)
int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

/* Constructor & destructor */
Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

  this->_accountIndex = Account::_nbAccounts; // set l'index du compte
  Account::_nbAccounts++;                     // augmente le nombre de
  Account::_totalAmount += initial_deposit;   // augmente le montant total

  Account::_displayTimestamp(); // affiche le timestamp
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

/* Getters */
int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
int Account::checkAmount(void) const { return Account::_totalAmount; }

/* Methods */
void Account::makeDeposit(int deposit) {
  if (deposit == 0)
    return;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;
  this->_amount += deposit;
  this->_nbDeposits++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > this->_amount) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused"
              << std::endl;
    return false;
  } else {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount - withdrawal
              << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    return true;
  }
}

/* Display Methods */
void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts()
            << ";total:" << Account::getTotalAmount()
            << ";deposits:" << Account::getNbDeposits()
            << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

static void _add_zero(std::string &str) {
  if (str.size() == 1)
    str = "0" + str;
}

void Account::_displayTimestamp(void) {
  std::time_t t = std::time(0);
  std::tm *now = std::localtime(&t);

  std::string year = to_string(now->tm_year + 1900);
  std::string month = to_string(now->tm_mon + 1);
  std::string day = to_string(now->tm_mday);
  std::string hour = to_string(now->tm_hour);
  std::string minute = to_string(now->tm_min);
  std::string second = to_string(now->tm_sec);

  // TODO : trouver un moyen plus propre de faire ca (plus c++)
  std::string *all[] = {&month, &day, &hour, &minute, &second};
  for (int i = 0; i < 5; i++)
    _add_zero(*all[i]);

  std::cout << "[" << year << month << day << "_" << hour << minute << second
            << "] ";
}
