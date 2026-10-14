#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Employee {
protected:
    string name;
    double monthlySalary;

public:
    Employee(string n, double salary) : name(n), monthlySalary(salary) {
    }

    virtual ~Employee() {
    }

    string getName() const {
        return name;
    }

    virtual double bonus() const = 0;
};

class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(string n, double salary) : Employee(n, salary) {
    }

    double bonus() const override {
        return monthlySalary * 0.10;
    }
};

class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(string n, double salary) : Employee(n, salary) {
    }

    double bonus() const override {
        return monthlySalary * 0.05;
    }
};

class Intern : public Employee {
public:
    Intern(string n, double salary) : Employee(n, salary) {
    }

    double bonus() const override {
        return 2000;
    }
};

int main() {
    map<string, function<unique_ptr<Employee>(string, double)>> factory = {
        {"FULLTIME", [](string n, double s) { return unique_ptr<Employee>(new FullTimeEmployee(n, s)); }},
        {"PARTTIME", [](string n, double s) { return unique_ptr<Employee>(new PartTimeEmployee(n, s)); }},
        {"INTERN", [](string n, double s) { return unique_ptr<Employee>(new Intern(n, s)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Employee>> employees;

    for (int i = 0; i < n; i++) {
        string type, name;
        double salary;
        cin >> type >> name >> salary;
        employees.push_back(factory[type](name, salary));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& e : employees) {
        double bonus = e->bonus();
        cout << e->getName() << ": " << bonus << endl;
        total += bonus;
    }

    cout << "Total Bonus: " << total << endl;

    return 0;
}
