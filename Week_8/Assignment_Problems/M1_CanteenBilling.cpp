#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Customer {
protected:
    double billAmount;

public:
    Customer(double amount) : billAmount(amount) {
    }

    virtual ~Customer() {
    }

    virtual string getType() const = 0;
    virtual double finalAmount() const = 0;
};

class Student : public Customer {
public:
    Student(double amount) : Customer(amount) {
    }

    string getType() const override {
        return "STUDENT";
    }

    double finalAmount() const override {
        return billAmount * 0.90;
    }
};

class Staff : public Customer {
public:
    Staff(double amount) : Customer(amount) {
    }

    string getType() const override {
        return "STAFF";
    }

    double finalAmount() const override {
        return billAmount * 0.95;
    }
};

class Guest : public Customer {
public:
    Guest(double amount) : Customer(amount) {
    }

    string getType() const override {
        return "GUEST";
    }

    double finalAmount() const override {
        return billAmount + 10;
    }
};

int main() {
    map<string, function<unique_ptr<Customer>(double)>> factory = {
        {"STUDENT", [](double a) { return unique_ptr<Customer>(new Student(a)); }},
        {"STAFF", [](double a) { return unique_ptr<Customer>(new Staff(a)); }},
        {"GUEST", [](double a) { return unique_ptr<Customer>(new Guest(a)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Customer>> bills;

    for (int i = 0; i < n; i++) {
        string type;
        double amount;
        cin >> type >> amount;
        bills.push_back(factory[type](amount));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& bill : bills) {
        double amount = bill->finalAmount();
        cout << bill->getType() << ": " << amount << endl;
        total += amount;
    }

    cout << "Total: " << total << endl;

    return 0;
}
