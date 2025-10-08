#include <iostream>
using namespace std;

class BankAccount {
    double balance;
public:
    BankAccount() {
        balance = 0.0;
        cout << "Default constructor called.\n";
    }
    BankAccount(double initialBalance) {
        balance = initialBalance;
        cout << "Parameterized constructor called.\n";
    }
    BankAccount(const BankAccount &obj) {
        balance = obj.balance;
        cout << "Copy constructor called.\n";
    }
    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!\n";
    }
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account1;
    cout << "\nAccount1 Balance: $" << account1.getBalance() << endl;
    BankAccount account2(1000.0);
    cout << "Account2 Balance: $" << account2.getBalance() << endl;
    BankAccount account3(account2);
    account3.withdraw(200);
    cout << "\nAfter withdrawing $200 from account3:" << endl;
    cout << "Account3 Balance: $" << account3.getBalance() << endl;
    cout << "Account2 Balance: $" << account2.getBalance() << endl;
    return 0;
}
