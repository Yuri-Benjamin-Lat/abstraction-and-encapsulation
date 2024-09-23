#include <iostream>
#include <limits>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful! New balance: " << balance << endl;
    }
    virtual void withdraw(double amount) = 0;
    virtual void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    static constexpr double MIN_BALANCE = 1000.0;
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {
        if (balance < MIN_BALANCE) {
            balance = MIN_BALANCE;
        }
    }
    void withdraw(double amount) override {
        if (balance - amount < MIN_BALANCE) {
            cout << "Insufficient funds! Minimum balance of " << MIN_BALANCE << " required." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(double initialBalance) : Account(initialBalance) {}
    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds! You can't withdraw more than the current balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};

int getValidChoiceMain() {
    int choice;
    bool condition = true;
    
    while (condition) {
        cout << ": ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 3) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return choice;
            } else {
                cout << "Invalid choice! Please enter a number (1-3)." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number (1-3)." << endl;
        }
    }
    return 0;
}

int getValidChoiceSub() {
    int choice;
    bool condition = true;
    
    while (condition) {
        cout << ": ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return choice;
            } else {
                cout << "Invalid choice! Please enter a number (1-4)." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number (1-4)." << endl;
        }
    }
    return 0;
}

double getValidAmount() {
    double amount;
    bool condition = true;
    
    while (condition) {
        cout << "Enter amount: ";
        if (cin >> amount) {
            if (amount > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return amount;
            } else {
                cout << "Invalid amount! Please enter a positive number." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a positive number." << endl;
        }
    }
    return 0;
}

void savingsAccountMenu(SavingsAccount& forSavingsAccount) {
    int choice;
    bool condition = true;

    while (condition) {
        cout << "\n============================";
        cout << "\nSavings Account Menu\n";
        cout << "============================\n";
        cout << "1 - Deposit\n";
        cout << "2 - Withdraw\n";
        cout << "3 - Check Balance\n";
        cout << "4 - Back\n";
        cout << "Enter your choice";
        choice = getValidChoiceSub();

        switch (choice) {
            case 1: {
                double amount = getValidAmount();
                forSavingsAccount.deposit(amount);
                break;
            }
            case 2: {
                double amount = getValidAmount();
                forSavingsAccount.withdraw(amount);
                break;
            }
            case 3:
                forSavingsAccount.checkBalance();
                break;
            case 4:
                return; // Go back to main menu
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void currentAccountMenu(CurrentAccount& forCurrentAccount) {
    int choice;
    bool condition = true;

    while (condition) {
        cout << "\n============================";
        cout << "\nCurrent Account Menu\n";
        cout << "============================\n";
        cout << "1 - Deposit\n";
        cout << "2 - Withdraw\n";
        cout << "3 - Check Balance\n";
        cout << "4 - Back\n";
        cout << "Enter your choice";
        choice = getValidChoiceSub();

        switch (choice) {
            case 1: {
                double amount = getValidAmount();
                forCurrentAccount.deposit(amount);
                break;
            }
            case 2: {
                double amount = getValidAmount();
                forCurrentAccount.withdraw(amount);
                break;
            }
            case 3:
                forCurrentAccount.checkBalance();
                break;
            case 4:
                return; // Go back to main menu
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

int main() {
    int choice;
    SavingsAccount forSavingsAccount(1000.0);
    CurrentAccount forCurrentAccount(0.0);
    bool condition = true;

    while (condition) {
        cout << "\n============================\n";
        cout << "         Main Menu\n";
        cout << "============================\n";
        cout << "1 - Savings Account\n";
        cout << "2 - Current Account\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice";
        choice = getValidChoiceMain();

        switch (choice) {
            case 1:
                savingsAccountMenu(forSavingsAccount);
                break;
            case 2:
                currentAccountMenu(forCurrentAccount);
                break;
            case 3:
                cout << "Exiting the program.\n";
                condition = false;
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
    return 0;
}
