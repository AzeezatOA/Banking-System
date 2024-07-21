/*Name: Azeezat Akinboro
Course: CSCE 1040
Description: Main file containing all the function definitions and program outputs. Program is a banking account system that gives user the option to open a new account, deposit, withdraw, or print accounts.
Information is stored in the class containers using vectors. 
A switch case is used to decide what actions to perform based on the user's choice. 
A loop is used to keep the program running until the user decides to exit.
*/
#include "Project3.h"

void openAccount(vector<Account> &accts){
  string userName;//store the user name inputted
  float initDeposit;//store the initial deposit
  int acctNum;//store the account number

  acctNum = Account::constAccountNumber;

  cout << "Enter your account name: ";
  cin.ignore();
  getline(cin, userName);

  cout << "Enter your initial deposit: $";
  cin >> initDeposit;

  accts.push_back(Account(acctNum, userName, initDeposit));//add the new account to the vector using the overloaded constructor
  /*accts.push_back(setCustomerName(userName));*/
  //ask about this in ooffice hours

  cout << "Account opened: " << acctNum << "---" << userName << ": $" << fixed << setprecision(2) << initDeposit << endl;
  Account::constAccountNumber++;//increment the account number
}

void depositMoney(vector<Account> &accts){
    int acctNumEntered;
    int count = 0;//keep track of if the account number matched
    float deposit;//amount deposited
    int accountIndex;//keep track of the index of the account number found

    cout << "Enter your account number: ";
    cin >> acctNumEntered;

    //check if the account exisit and keep track of its index
    for(int i = 0; i < accts.size(); ++i){
        if(acctNumEntered == accts.at(i).getAccountNumber()){
            ++count;
            accountIndex = i;
        }
    }

    //perform the action needed if the account exists and print error message if not
    if(count > 0){
        cout << "Enter deposit amount: $";
        cin >> deposit;

        accts.at(accountIndex).deposit(deposit);//access the account at the index and use the deposit function
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << accts.at(accountIndex).getAccountBalance() << endl;
    }
    else{
        cout << "Error. Please enter a valid acccount number." << endl;
    }
}

void withdrawMoney(vector<Account> &accts){
    int acctNumEntered;
    int count = 0;//keep track of if the account number matched
    float withdraw;//amount withdrawn
    int accountIndex;//keep track of the index of the account number found
    string name;

    cout << "Enter your account number: ";
    cin >> acctNumEntered;

    for(int i = 0; i < accts.size(); ++i){
        if(acctNumEntered == accts.at(i).getAccountNumber()){
            ++count;
            accountIndex = i;
        }
    }

    if(count > 0){
        cin.ignore();
        cout << "Enter the account name: ";
        getline(cin, name);
        if(name == accts.at(accountIndex).getCustomerName()){
            cout << "Enter amount to withdraw: $";
            cin >> withdraw;

            //check if there are sufficient funds to withdraw
            if(withdraw < accts.at(accountIndex).getAccountBalance()){
            accts.at(accountIndex).withdraw(withdraw);
            cout << "Withdraw successful. New balance: " << fixed << setprecision(2) << accts.at(accountIndex).getAccountBalance() << endl;
            }
            else{
                cout << "Insufficient funds" << endl;
            }
        }
        else{
            cout << "Account number and name do not match. Access denied." << endl;
        }
    }
    else{
        cout << "Error. Please enter a valid acccount number." << endl;
    }
}

void transferMoney(vector<Account> &accts){
    int sourceAccount;
    int destAccount;
    int count;
    int sourceIndex;
    int destIndex;

    cout << "Enter the account number to transfer from: ";
    cin >> sourceAccount;

    cout << "Enter the account number to transfer to: ";
    cin >> destAccount;

    for(unsigned int i = 0; i < accts.size(); ++i){
        if(sourceAccount == accts.at(i).getAccountNumber()){
            ++count;
            sourceIndex = i;
        }
        if(destAccount == accts.at(i).getAccountNumber()){
            ++count;
            destIndex = i;
        }
    }

    if(count == 2){
        if(accts.at(sourceIndex).getAccountBalance() >= 40){
            accts.at(sourceIndex).transferOut();
            accts.at(destIndex).transferIn();

            cout << "Transfer successful." << endl;
            cout << "Account #" << accts.at(sourceIndex).getAccountNumber() << " balance: " << accts.at(sourceIndex).getAccountBalance() << endl;
            cout << "Account #" << accts.at(destIndex).getAccountNumber() << " balance: " << accts.at(destIndex).getAccountBalance() << endl;
        }
        else{
            cout << "Insufficient funds in account #" << accts.at(sourceIndex).getAccountNumber() << endl;
        }
    }
    else{
        cout << "Error. Please enter valid account numbers." << endl;
    }
}

void printAccounts(vector<Account> &accts){
  if(accts.size() == 0){
    //if there are no accounts stored
    cout << "There are no accounts available." << endl;
  }
  else{
    cout << "Account Number | Name       | Balance" << endl;
    for (int i = 0; i < accts.size(); ++i){
        cout << "          " << accts.at(i).getAccountNumber() << " | " << accts.at(i).getCustomerName() << " | $" << accts.at(i).getAccountBalance() << endl;
    }
  }
}

int main(){
  cout << "*****************************************************" << endl;
  cout << "*           Name: Azeezat Akinboro                  *" << endl;
  cout << "*                 EUID: aoa0183                     *"<< endl;
  cout << "*        Email: azeezatakinboro@my.unt.edu          *" << endl;
  cout << "* Department name: Computer Science and Engineering *" << endl;
  cout << "*               Course: CSCE 1040                   *" << endl;
  cout << "*****************************************************" << endl;

  int choice;
  enum options{//enumeration to use switch case function
    open = 1,
    deposit = 2,
    withdraw = 3,
    transfer = 4,
    print = 5,
    exit = 6
  };
  options choices;
  vector<Account>accts;//accts object of Account class

  cout << "------------------------------------" << endl;
  cout << "1. Open new account" << endl;
  cout << "2. Deposit into account" << endl;
  cout << "3. Withdraw from account" << endl;
  cout << "4. Fast tranfer $40 into account" << endl;
  cout << "5. Print a list of all accounts" << endl;
  cout << "6. End transaction" << endl;
  cout << "------------------------------------" << endl;
  cout << "Enter your choice: ";

  cin >> choice;
  choices = static_cast<options>(choice);//cast choice to options
  
  while(choices){//loop to keep running
    switch(choices){
      case open:
        openAccount(accts);
        break;
      
      case deposit:
        depositMoney(accts);
        break;
      
      case withdraw:
        withdrawMoney(accts);
        break;
      
      case transfer:
        transferMoney(accts);
        break;

      case print:
        printAccounts(accts);
        break;
      
      case exit:
        cout << "Thanks for using this program, bye!" << endl;
        return 0;//end program if this option is chosen
        break;

      default:
        cout << "Invalid choice. Please enter a valid option" << endl;
        break;
    }

    if(choices != exit){
        cout << "------------------------------------" << endl;
      cout << "1. Open new account" << endl;
      cout << "2. Deposit into account" << endl;
      cout << "3. Withdraw from account" << endl;
      cout << "4. Fast transfer $40 into account" << endl;
      cout << "5. Print a list of all accounts" << endl;
      cout << "6. End transaction" << endl;
      cout << "------------------------------------" << endl;
      cout << "Enter your choice: ";

      cin >> choice;
      choices = static_cast<options>(choice);
    }
  }
  
}