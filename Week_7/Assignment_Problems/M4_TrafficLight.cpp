#include <iostream>
#include <string>
using namespace std;

class TrafficLight {
private:
    string color;
    const string id;

public:
    TrafficLight(string lightId)
        : id(lightId), color("RED") {
    }

    void next() {
        if (color == "RED") {
            color = "GREEN";
        } else if (color == "GREEN") {
            color = "YELLOW";
        } else {
            color = "RED";
        }
    }

    string getColor() const {
        return color;
    }
};

int main() {
    TrafficLight t("TL-9");

    cout << t.getColor() << endl;

    t.next();
    cout << t.getColor() << endl;

    t.next();
    cout << t.getColor() << endl;

    t.next();
    cout << t.getColor() << endl;

    return 0;
}