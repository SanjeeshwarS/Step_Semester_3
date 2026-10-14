#include <iostream>
using namespace std;

char gradeFor(int marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 75) {
        return 'B';
    } else if (marks >= 60) {
        return 'C';
    } else if (marks >= 40) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int marks;

    while (cin >> marks) {
        cout << "Grade " << gradeFor(marks) << endl;
    }

    return 0;
}
