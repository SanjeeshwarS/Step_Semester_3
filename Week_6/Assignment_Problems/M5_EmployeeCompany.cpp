#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string empName;
    double salary;

    static string companyName;
    static int employeeCount;

public:
    Employee(string name, double sal) {
        empName = name;
        salary = sal;
        employeeCount++;
    }

    static void printCompanyInfo() {
        cout << companyName << endl;
        cout << "Employees on record: "
             << employeeCount << endl;
    }
};

string Employee::companyName = "Bright Horizon Technologies";
int Employee::employeeCount = 0;

int main() {
    Employee e1("Divya", 65000);
    Employee e2("Arjun", 45000);
    Employee e3("Rahul", 55000);

    Employee::printCompanyInfo();

    return 0;
}