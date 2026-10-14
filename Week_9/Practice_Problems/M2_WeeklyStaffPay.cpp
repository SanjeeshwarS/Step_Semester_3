#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class StaffMember {
protected:
    string name;

public:
    StaffMember(string n) : name(n) {
    }

    virtual ~StaffMember() {
    }

    string getName() const {
        return name;
    }

    virtual double weeklyPay() const = 0;
};

class FullTimeStaff : public StaffMember {
private:
    double weeklySalary;

public:
    FullTimeStaff(string n, double salary) : StaffMember(n), weeklySalary(salary) {
    }

    double weeklyPay() const override {
        return weeklySalary;
    }
};

class HourlyStaff : public StaffMember {
private:
    double hours;
    double rate;

public:
    HourlyStaff(string n, double h, double r) : StaffMember(n), hours(h), rate(r) {
    }

    double weeklyPay() const override {
        if (hours <= 40) {
            return hours * rate;
        }
        return 40 * rate + (hours - 40) * rate * 1.5;
    }
};

class InternStaff : public StaffMember {
private:
    double stipend;

public:
    InternStaff(string n, double s) : StaffMember(n), stipend(s) {
    }

    double weeklyPay() const override {
        return stipend;
    }
};

int main() {
    map<string, function<unique_ptr<StaffMember>(string, istream&)>> factory = {
        {"FULLTIME", [](string n, istream& in) {
            double salary;
            in >> salary;
            return unique_ptr<StaffMember>(new FullTimeStaff(n, salary));
        }},
        {"HOURLY", [](string n, istream& in) {
            double hours, rate;
            in >> hours >> rate;
            return unique_ptr<StaffMember>(new HourlyStaff(n, hours, rate));
        }},
        {"INTERN", [](string n, istream& in) {
            double stipend;
            in >> stipend;
            return unique_ptr<StaffMember>(new InternStaff(n, stipend));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<StaffMember>> staff;

    for (int i = 0; i < n; i++) {
        string type, name;
        cin >> type >> name;
        staff.push_back(factory[type](name, cin));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& s : staff) {
        double pay = s->weeklyPay();
        cout << s->getName() << ": " << pay << endl;
        total += pay;
    }

    cout << "Total Payroll: " << total << endl;

    return 0;
}
