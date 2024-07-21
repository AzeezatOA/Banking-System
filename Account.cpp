/*Name: Azeezat Akinboro
Course: CSCE 1040
Description: File containing all the class Account function definitions
*/
#include "Account.h"

Account::Account(){
  accountNumber = 00;
  customerName = "No Name";
  accountBalance = 0.00;
}

Account::Account(int accountNumber, string customerName, double accountBalance){
  this -> accountNumber = accountNumber;
  this -> customerName = customerName;
  this -> accountBalance = accountBalance;
}

Account::~Account(){
  //cout << "Destructor called" << endl;
}

int Account::constAccountNumber = 1000;//initialization of the static integer

void Account::setAccountNumber(int accountNumber){
  this -> accountNumber = accountNumber;
}

void Account::setCustomerName(string customerName){
  this -> customerName = customerName;
}

void Account::setAccountBalance(double accountBalance){
  this -> accountBalance = accountBalance;
}

int Account::getAccountNumber() const{
  return accountNumber;
}

string Account::getCustomerName() const{
  return customerName;
}

float Account::getAccountBalance() const{
  return accountBalance;
}

void Account::deposit(float deposit){
  accountBalance += deposit;
}

void Account::withdraw(float withdraw){
  accountBalance -= withdraw;
}

void Account::transferIn(){
    accountBalance += 40;
}

void Account::transferOut(){
    accountBalance -= 40;
}