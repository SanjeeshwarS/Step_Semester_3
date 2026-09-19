#include <iostream>
#include <string>
using namespace std;

class NameTag {
private:
    const string firstName;
    const char lastInitial;

public:
    NameTag(string fullName)
        : firstName(fullName.substr(0, fullName.find(' '))),
          lastInitial(fullName[fullName.find(' ') + 1]) {
    }

    string getNickname() const {
        return firstName + " " + lastInitial + ".";
    }
};

int main() {
    NameTag tag("Maria Gomez");

    cout << tag.getNickname() << endl;

    return 0;
}