#include <iostream>
#include <string>
using namespace std;

class PasswordChecker {
private:
    const string password;

public:
    PasswordChecker(string pass) : password(pass) {
    }

    string getStrength() const {
        int length = password.length();

        if (length < 6) {
            return "Weak";
        } else if (length <= 9) {
            return "Medium";
        } else {
            return "Strong";
        }
    }
};

int main() {
    PasswordChecker pc("abcd");
    PasswordChecker pc2("abcdefghij");

    cout << pc.getStrength() << endl;
    cout << pc2.getStrength() << endl;

    return 0;
}