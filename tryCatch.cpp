// Custom Exception
#include <iostream>
#include <exception>
using namespace std;

// Custom Exception
class InsufficientBalanceException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient balance!";
    }
};

// Bank Account class (OOP)
class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientBalanceException(); // 🚨 throw
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000);

    try {
        acc.withdraw(6000); // ❌ will throw exception
    }
    catch (const InsufficientBalanceException& e) { // ✅ catch
        cout << e.what() << endl;
    }

    return 0;
}

===================================================================================================================
// Basic Exception 

#include <iostream>
#include <stdexcept>  // for standard exceptions
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Error: Insufficient balance!"); // built-in exception
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000);

    try {
        acc.withdraw(6000); // ❌ will throw
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}