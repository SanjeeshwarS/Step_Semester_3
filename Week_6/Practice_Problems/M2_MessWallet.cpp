#include <iostream>
using namespace std;

class MessWallet {
private:
    double balance;

public:
    MessWallet(double opening) {
        if (opening < 0) {
            cout << "Warning: Negative balance not allowed" << endl;
            balance = 0;
        } else {
            balance = opening;
        }
    }

    void topUp(double amount) {
        if (amount <= 0) {
            cout << "Invalid top-up amount" << endl;
        } else {
            balance += amount;
            cout << "Balance after top-up: "
                 << balance << endl;
        }
    }

    void deduct(double amount) {
        if (amount <= 0) {
            cout << "Invalid deduction amount" << endl;
        } else if (amount > balance) {
            cout << "Deduct rejected: insufficient balance" << endl;
        } else {
            balance -= amount;
            cout << "Amount deducted: "
                 << amount << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    MessWallet wallet(500);

    wallet.topUp(200);
    wallet.deduct(1000);

    cout << "Final balance: "
         << wallet.getBalance() << endl;

    return 0;
}