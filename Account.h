/*Name: Azeezat Akinboro
Course: CSCE 1040
Description: Header file containing all the directives and class and function declarations
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account{
  public:
    Account();//default constructor
    Account(int accountNumber, string customerName, double accountBalance);//constructor overload
    ~Account();//destructor
    //setters
    void setAccountNumber(int accountNumber);
    void setCustomerName(string customerName);
    void setAccountBalance(double accountBalance);
    //getters
    int getAccountNumber() const;
    string getCustomerName() const;
    float getAccountBalance() const;
    //action functions
    void deposit(float deposit);
    void withdraw(float withdraw);
    void transferIn();
    void transferOut();

    static int constAccountNumber;

  private:
    string customerName;
    float accountBalance;
    int accountNumber;
};

#endif