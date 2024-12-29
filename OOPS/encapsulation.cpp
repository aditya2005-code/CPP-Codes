#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
        }
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    void setAccountHolderName(const string& name) {
        accountHolderName = name;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". Remaining balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal denied." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("Aditya Sharma", "123456789", 5000);

    account.displayAccountDetails();

    cout << "\nDepositing money..." << endl;
    account.deposit(1500);

    cout << "\nWithdrawing money..." << endl;
    account.withdraw(2000);

    cout << "\nAttempting to withdraw too much..." << endl;
    account.withdraw(8000);

    cout << "\nChanging account holder name..." << endl;
    account.setAccountHolderName("Amit Verma");

    cout << "\nUpdated Account Details:" << endl;
    account.displayAccountDetails();

    return 0;
}
