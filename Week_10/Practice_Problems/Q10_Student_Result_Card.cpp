#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Student {
private:
    string name;
    int marks[3];

public:
    Student(string n, int m1, int m2, int m3) : name(n) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    double average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    char grade() const {
        double avg = average();

        if (avg >= 75) {
            return 'B';
        } else if (avg >= 60) {
            return 'C';
        } else if (avg >= 40) {
            return 'D';
        } else {
            return 'F';
        }
    }

    string upperName() const {
        string upper = name;
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        return upper;
    }

    void printResultCard() const {
        cout << upperName() << ": Average "
             << fixed << setprecision(1) << average()
             << ", Grade " << grade() << endl;
    }
};

int main() {
    vector<Student> students = {
        Student("Asha", 80, 90, 70),
        Student("Ravi", 60, 55, 50)
    };

    for (const Student& s : students) {
        s.printResultCard();
    }

    return 0;
}
