// THE LEVISKOVS SUBSTITUTION PRINCIPLE STATES THAT A BASE CLASS IS SUBSTITUTABLE BY ITS DERIVED CLASS
#include<bits/stdc++.h>
using namespace std;


class BankAccount {
public:
    virtual void deposit(int amount) {
        cout << "Deposited: " << amount << endl;
    }

    virtual ~BankAccount() {}
};

// Only withdrawable accounts inherit this
class WithdrawableAccount : public BankAccount {
public:
    virtual void withdraw(int amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
public:
    void withdraw(int amount) override {
        cout << "Savings withdraw: " << amount << endl;
    }
};

class CurrentAccount : public WithdrawableAccount {
public:
    void withdraw(int amount) override {
        cout << "Current withdraw: " << amount << endl;
    }
};

class FixedDepositAccount : public BankAccount {
    // No withdraw → correct (LSP followed)
};

// Function using base abstraction
void processWithdrawal(WithdrawableAccount* acc) {
    acc->withdraw(1000);
}

int main() {
    SavingsAccount s;
    CurrentAccount c;
    FixedDepositAccount fd;

    // Works correctly (LSP satisfied)
    processWithdrawal(&s);
    processWithdrawal(&c);

    // Deposit works for all accounts
    BankAccount* acc1 = &s;
    BankAccount* acc2 = &fd;

    acc1->deposit(500);
    acc2->deposit(1000);

    return 0;
}