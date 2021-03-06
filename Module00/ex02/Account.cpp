#include "Account.hpp"

#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return  _totalNbWithdrawals;
}

Account::Account(int initial_deposit) {
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex\
        << ";amount:" << _amount\
        << ";created" << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount\
        << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals\
        << std::endl;
}

void Account::_displayTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year\
            << std::setw(2) << std::setfill('0') << ltm->tm_mon\
            << std::setw(2) << std::setfill('0') << ltm->tm_mday\
            << "_"\
            << std::setw(2) << std::setfill('0') << ltm->tm_hour\
            << std::setw(2) << std::setfill('0') << ltm->tm_min\
            << std::setw(2) << std::setfill('0') << ltm->tm_sec\
            << "] ";
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex\
        << ";amount:" << _amount\
        << ";deposits:" << _nbDeposits\
        << ";withdrawals:" << _nbWithdrawals\
        << std::endl;
}

void Account::makeDeposit(int deposit) {
    int _p_amount = _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _displayTimestamp();
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex\
        << ";p_amount:" << _p_amount\
        << ";deposit:" << deposit\
        << ";amount:" << _amount\
        << ";nb_deposits:" << _nbDeposits\
        << std::endl;
}

// int checkAmount*

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    bool ret = true;
    std::cout << "index:" << _accountIndex\
        << ";p_amount:" << _amount <<";";
    if (_amount - withdrawal < 0) {
        std::cout << "withdrawal:refused" << std::endl;
        ret = false;
    } else {
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal\
            << ";amount:" << _amount\
            << ";nb_withdrawals:" << _nbWithdrawals\
            << std::endl;
    }
    return ret;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"\
			  << _amount << ";closed\n";
}