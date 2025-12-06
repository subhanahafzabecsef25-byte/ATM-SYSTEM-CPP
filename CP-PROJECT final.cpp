#include <iostream>
using namespace std;

// Function declarations
void showMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    float balance = 1000.0;  // Initial balance
    int pin, userPin = 1234; // Pre-set PIN
    int option;
    bool authenticated = false;

    cout << "=============================\n";
    cout << "     Welcome to My ATM       \n";
    cout << "=============================\n";

    // PIN verification
    for (int i = 0; i < 3; i++) {
        cout << "\nEnter your 4-digit PIN: ";
        cin >> pin;

        if (pin == userPin) {
            authenticated = true;
            break;
        } else {
            cout << "Incorrect PIN. Try again.\n";
        }
    }

    if (!authenticated) {
        cout << "\nToo many incorrect attempts. Card blocked!\n";
        return 0;
    }

    do {
        showMenu();
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                cout << "\nThank you for using My ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (option != 4);

    return 0;
}

// Function to display menu
void showMenu() {
    cout << "\n=============================\n";
    cout << "         ATM Menu            \n";
    cout << "=============================\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "=============================\n";
}

// Function to check balance
void checkBalance(float balance) {
    cout << "\nYour current balance is: $" << balance << endl;
}

// Function to deposit money
float depositMoney(float balance) {
    float amount;
    cout << "\nEnter amount to deposit: $";
    cin >> amount;

    if (amount <= 0)
        cout << "Invalid amount!" << endl;
    else {
        balance += amount;
        cout << "Deposit successful! New balance: $" << balance << endl;
    }

    return balance;
}

// Function to withdraw money
float withdrawMoney(float balance) {
    float amount;
    cout << "\nEnter amount to withdraw: $";
    cin >> amount;

    if (amount <= 0)
        cout << "Invalid amount!" << endl;
    else if (amount > balance)
        cout << "Insufficient funds!" << endl;
    else {
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
    }

    return balance;
}