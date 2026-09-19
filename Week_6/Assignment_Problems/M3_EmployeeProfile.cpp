#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string empId;
    string empName;
    double salary;
    bool isIntern;

public:
    Employee(string id, string name, double sal) {
        empId = id;
        empName = name;
        salary = sal;
        isIntern = false;
    }

    Employee(string id, string name) : Employee(id, name, 0) {
        isIntern = true;
    }

    void printProfile() {
        cout << empId << " | "
             << empName << " | Rs "
             << salary << " | Intern: "
             << boolalpha << isIntern << endl;
    }
};

int main() {
    Employee permanent("E-101", "Divya", 65000);
    Employee intern("E-102", "Arjun");

    permanent.printProfile();
    intern.printProfile();

    return 0;
}