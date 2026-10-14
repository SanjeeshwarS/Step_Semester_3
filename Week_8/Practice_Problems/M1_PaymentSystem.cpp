#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Payment {
protected:
    double amount;

public:
    Payment(double amt) : amount(amt) {
    }

    virtual ~Payment() {
    }

    virtual string getType() const = 0;
    virtual double finalAmount() const = 0;
};

class CardPayment : public Payment {
public:
    CardPayment(double amt) : Payment(amt) {
    }

    string getType() const override {
        return "CARD";
    }

    double finalAmount() const override {
        return amount * 1.02;
    }
};

class WalletPayment : public Payment {
public:
    WalletPayment(double amt) : Payment(amt) {
    }

    string getType() const override {
        return "WALLET";
    }

    double finalAmount() const override {
        return amount * 1.01;
    }
};

class BankTransferPayment : public Payment {
public:
    BankTransferPayment(double amt) : Payment(amt) {
    }

    string getType() const override {
        return "BANKTRANSFER";
    }

    double finalAmount() const override {
        return amount;
    }
};

int main() {
    map<string, function<unique_ptr<Payment>(double)>> factory = {
        {"CARD", [](double a) { return unique_ptr<Payment>(new CardPayment(a)); }},
        {"WALLET", [](double a) { return unique_ptr<Payment>(new WalletPayment(a)); }},
        {"BANKTRANSFER", [](double a) { return unique_ptr<Payment>(new BankTransferPayment(a)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Payment>> payments;

    for (int i = 0; i < n; i++) {
        string type;
        double amount;
        cin >> type >> amount;
        payments.push_back(factory[type](amount));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& p : payments) {
        double finalAmount = p->finalAmount();
        cout << p->getType() << ": " << finalAmount << endl;
        total += finalAmount;
    }

    cout << "Total: " << total << endl;

    return 0;
}
