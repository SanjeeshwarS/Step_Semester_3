#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year;

    while (cin >> year) {
        cout << (isLeapYear(year) ? "Leap year" : "Not a leap year") << endl;
    }

    return 0;
}
