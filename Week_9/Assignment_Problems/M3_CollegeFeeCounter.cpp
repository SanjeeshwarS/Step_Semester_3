#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class BusUser {
public:
    virtual ~BusUser() {
    }

    static double transportFee() {
        return 12000;
    }
};

class Student {
protected:
    string name;

public:
    Student(string n) : name(n) {
    }

    virtual ~Student() {
    }

    string getName() const {
        return name;
    }

    virtual double tuitionAndCharges() const = 0;
};

class DayScholar : public Student, public BusUser {
public:
    DayScholar(string n) : Student(n) {
    }

    double tuitionAndCharges() const override {
        return 40000;
    }
};

class Hosteller : public Student {
public:
    Hosteller(string n) : Student(n) {
    }

    double tuitionAndCharges() const override {
        return 40000 + 60000;
    }
};

class ScholarshipStudent : public Student, public BusUser {
public:
    ScholarshipStudent(string n) : Student(n) {
    }

    double tuitionAndCharges() const override {
        return 40000 / 2;
    }
};

double totalFee(const Student& s) {
    double fee = s.tuitionAndCharges();

    if (dynamic_cast<const BusUser*>(&s) != nullptr) {
        fee += BusUser::transportFee();
    }

    return fee;
}

int main() {
    map<string, function<unique_ptr<Student>(string)>> factory = {
        {"DAY_SCHOLAR", [](string n) { return unique_ptr<Student>(new DayScholar(n)); }},
        {"HOSTELLER", [](string n) { return unique_ptr<Student>(new Hosteller(n)); }},
        {"SCHOLAR", [](string n) { return unique_ptr<Student>(new ScholarshipStudent(n)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Student>> students;

    for (int i = 0; i < n; i++) {
        string type, name;
        cin >> type >> name;
        students.push_back(factory[type](name));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& s : students) {
        double fee = totalFee(*s);
        cout << s->getName() << ": " << fee << endl;
        total += fee;
    }

    cout << "Total Collected: " << total << endl;

    return 0;
}
