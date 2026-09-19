#include <iostream>
#include <string>
using namespace std;

class Locker {
private:
    string code;
    const int lockerNumber;

public:
    Locker(int number, string initialCode)
        : lockerNumber(number), code(initialCode) {
    }

    void changeCode(string currentCode, string newCode) {
        if (currentCode == code) {
            code = newCode;
            cout << "Code changed successfully" << endl;
        } else {
            cout << "Code change rejected" << endl;
        }
    }
};

int main() {
    Locker l(101, "1234");

    l.changeCode("1234", "5678");
    l.changeCode("0000", "9999");

    return 0;
}