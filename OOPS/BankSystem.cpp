#include <bits/stdc++.h>
using namespace std;

class Account {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    Account(string accNum, string name, double bal)
        : accountNumber(accNum), holderName(name), balance(bal) {}

    string getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    void setBalance(double bal) { balance = bal; }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    virtual void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string name, double bal, double rate)
        : Account(accNum, name, bal), interestRate(rate) {}

    void deposit(double amount) override {
        if (amount > 0) {
            setBalance(getBalance() + amount);
            cout << "Deposited " << amount << " into Savings Account " << getAccountNumber() << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && getBalance() - amount >= 500) {
            setBalance(getBalance() - amount);
            cout << "Withdrawn " << amount << " from Savings Account " << getAccountNumber() << endl;
        } else {
            cout << "Withdrawal denied! Minimum balance of 500 must be maintained." << endl;
        }
    }

    void displayDetails() const override {
        cout << "\n[ Savings Account ]" << endl;
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, string name, double bal, double limit)
        : Account(accNum, name, bal), overdraftLimit(limit) {}

    void deposit(double amount) override {
        if (amount > 0) {
            setBalance(getBalance() + amount);
            cout << "Deposited " << amount << " into Current Account " << getAccountNumber() << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && getBalance() - amount >= -overdraftLimit) {
            setBalance(getBalance() - amount);
            cout << "Withdrawn " << amount << " from Current Account " << getAccountNumber() << endl;
        } else {
            cout << "Withdrawal denied! Overdraft limit exceeded." << endl;
        }
    }

    void displayDetails() const override {
        cout << "\n[ Current Account ]" << endl;
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount("101", "Aditya", 5000, 5.0));
    accounts.push_back(new CurrentAccount("102", "John", 2000, 1000));

    accounts[0]->deposit(2000);
    accounts[1]->withdraw(2500);

    accounts[0]->withdraw(4800);
    accounts[1]->withdraw(1500);

    for (auto acc : accounts) {
        acc->displayDetails();
    }

    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}
