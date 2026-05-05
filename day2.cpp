#include <iostream>
using namespace std;

class BankAccount {
private:
    string holderName;
    double balance;
    double minBalance;

public:
    // Constructor
    BankAccount(string name, double initialBalance = 0) {
        holderName = name;
        balance = initialBalance;
        minBalance = 100; // bonus: minimum balance rule
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }

        if (balance - amount < minBalance) {
            cout << "Withdrawal denied: Minimum balance requirement not met." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display balance
    void displayBalance() {
        cout << "Account Holder: " << holderName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("Alice", 500);

    account.displayBalance();
    cout << "----" << endl;

    account.deposit(200);
    account.withdraw(100);
    account.withdraw(600); // should fail

    cout << "----" << endl;
    account.displayBalance();

    return 0;
}