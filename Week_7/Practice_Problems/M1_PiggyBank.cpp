#include <iostream>
#include <string>
using namespace std;

class PiggyBank {
private:
    double savings;
    const string id;

public:
    PiggyBank(string bankId)
        : id(bankId), savings(0) {
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit" << endl;
            return;
        }

        savings += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > savings) {
            cout << "Withdrawal rejected" << endl;
            return;
        }

        savings -= amount;
    }

    double getSavings() const {
        return savings;
    }
};

int main() {
    PiggyBank pb("PB-1");

    pb.deposit(100);
    cout << "Savings: " << pb.getSavings() << endl;

    pb.withdraw(30);
    cout << "Savings: " << pb.getSavings() << endl;

    pb.withdraw(500);
    cout << "Savings: " << pb.getSavings() << endl;

    return 0;
}