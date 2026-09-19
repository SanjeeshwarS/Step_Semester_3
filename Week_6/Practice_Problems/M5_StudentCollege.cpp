#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double attendance;

    static string collegeName;
    static int studentCount;

public:
    Student(string n, double att) {
        name = n;
        attendance = att;
        studentCount++;
    }

    static void printCollegeInfo() {
        cout << collegeName << endl;
        cout << "Students created: "
             << studentCount << endl;
    }
};

string Student::collegeName =
    "SRM Institute of Science and Technology";

int Student::studentCount = 0;

int main() {
    Student s1("Ravi", 90);
    Student s2("Anitha", 95);

    Student::printCollegeInfo();

    return 0;
}