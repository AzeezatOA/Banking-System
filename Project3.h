/*Name: Azeezat Akinboro
Course: CSCE 1040
Description: Header file containing all the function declarations for the main program
*/
#include "Account.h"
#include <iomanip>//for set precision

void openAccount(vector<Account> &accts);//function to open account
void depositMoney(vector<Account> &accts);//function to deposit money
void withdrawMoney(vector<Account> &accts);//function to withdraw money
void printAccounts(vector<Account> &accts);//function to print all the accounts
void transferMoney(vector<Account> &accts);//function to transfer money