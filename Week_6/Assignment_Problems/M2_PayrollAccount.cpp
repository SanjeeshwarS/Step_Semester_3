#include <iostream>
using namespace std;

class PayrollAccount {
private:
    double basicSalary;
    double bonus;

public:
    PayrollAccount(double salary) {
        if (salary < 0) {
            cout << "Warning: Negative salary not allowed" << endl;
            basicSalary = 0;
        } else {
            basicSalary = salary;
        }

        bonus = 0;
    }

    void creditBonus(double amount) {
        if (amount <= 0) {
            cout << "Invalid bonus amount" << endl;
        } else {
            bonus += amount;
            cout << "Bonus credited: Rs " << amount << endl;
        }
    }

    void deductTax(double percent) {
        if (percent < 0 || percent > 100) {
            cout << "Invalid tax percentage" << endl;
        } else {
            basicSalary -= basicSalary * percent / 100;
            cout << "Tax deducted: " << percent << "%" << endl;
        }
    }

    double getNetSalary() {
        return basicSalary + bonus;
    }
};

int main() {
    PayrollAccount account(50000);

    account.creditBonus(5000);
    account.deductTax(10);

    cout << "Net salary: Rs "
         << account.getNetSalary() << endl;

    return 0;
}