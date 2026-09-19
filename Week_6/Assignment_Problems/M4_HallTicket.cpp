#include <iostream>
#include <string>
using namespace std;

class HallTicket {
public:
    string studentName;
    int seatNumber;

    HallTicket(string name, int seat) {
        studentName = name;
        seatNumber = seat;
    }
};

int main() {
    HallTicket* priya = new HallTicket("Priya", 0);

    HallTicket* copy = priya;

    copy->seatNumber = 45;

    HallTicket* separate = new HallTicket("Priya", 45);

    cout << "Priya's seatNumber (via first variable):" << endl;
    cout << priya->seatNumber << endl;

    cout << "copy == priya: "
         << boolalpha << (copy == priya) << endl;

    cout << "separate == priya: "
         << boolalpha << (separate == priya) << endl;

    delete priya;
    delete separate;

    return 0;
}