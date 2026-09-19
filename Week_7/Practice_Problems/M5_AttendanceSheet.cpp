#include <iostream>
#include <string>
using namespace std;

class AttendanceSheet {
private:
    string* students;
    const int maxStudents;
    int presentCount;

public:
    AttendanceSheet(int size)
        : maxStudents(size), presentCount(0) {
        students = new string[maxStudents];
    }

    void markPresent(string name) {
        if (isPresent(name)) {
            return;
        }

        if (presentCount >= maxStudents) {
            cout << "Attendance sheet is full" << endl;
            return;
        }

        students[presentCount] = name;
        presentCount++;
    }

    int getPresentCount() const {
        return presentCount;
    }

    bool isPresent(string name) const {
        for (int i = 0; i < presentCount; i++) {
            if (students[i] == name) {
                return true;
            }
        }

        return false;
    }

    ~AttendanceSheet() {
        delete[] students;
    }
};

int main() {
    AttendanceSheet sheet(30);

    sheet.markPresent("Ana");
    sheet.markPresent("Ben");
    sheet.markPresent("Ana");

    cout << "Present count: "
         << sheet.getPresentCount() << endl;

    cout << boolalpha;

    cout << "Ben present: "
         << sheet.isPresent("Ben") << endl;

    cout << "Chen present: "
         << sheet.isPresent("Chen") << endl;

    return 0;
}