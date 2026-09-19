#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string code;
    string title;
    int credits;
    int labCredits;

public:
    Course(string c, string t, int cr, int lab) {
        code = c;
        title = t;
        credits = cr;
        labCredits = lab;
    }

    Course(string c, string t, int cr)
        : Course(c, t, cr, 0) {
    }

    int totalCredits() {
        return credits + labCredits;
    }

    string getCode() {
        return code;
    }
};

int main() {
    Course theory("21CSC201J", "Data Structures", 4);
    Course lab("21CSC205L", "DSA Lab", 3, 1);

    cout << theory.getCode()
         << " total credits: "
         << theory.totalCredits() << endl;

    cout << lab.getCode()
         << " total credits: "
         << lab.totalCredits() << endl;

    return 0;
}