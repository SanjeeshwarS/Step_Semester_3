#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Room {
protected:
    int units;

public:
    Room(int u) : units(u) {
    }

    virtual ~Room() {
    }

    virtual string getType() const = 0;
    virtual double bill() const = 0;
};

class SingleRoom : public Room {
public:
    SingleRoom(int u) : Room(u) {
    }

    string getType() const override {
        return "SINGLE";
    }

    double bill() const override {
        return 8.0 * units;
    }
};

class SharedRoom : public Room {
private:
    int occupants;

public:
    SharedRoom(int u, int occ) : Room(u), occupants(occ) {
    }

    string getType() const override {
        return "SHARED";
    }

    double bill() const override {
        return 6.0 * units / occupants;
    }
};

class AcRoom : public Room {
public:
    AcRoom(int u) : Room(u) {
    }

    string getType() const override {
        return "AC";
    }

    double bill() const override {
        return 10.0 * units + 200;
    }
};

int main() {
    map<string, function<unique_ptr<Room>(istream&)>> factory = {
        {"SINGLE", [](istream& in) {
            int u;
            in >> u;
            return unique_ptr<Room>(new SingleRoom(u));
        }},
        {"SHARED", [](istream& in) {
            int u, occ;
            in >> u >> occ;
            return unique_ptr<Room>(new SharedRoom(u, occ));
        }},
        {"AC", [](istream& in) {
            int u;
            in >> u;
            return unique_ptr<Room>(new AcRoom(u));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Room>> rooms;

    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        rooms.push_back(factory[type](cin));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& r : rooms) {
        double bill = r->bill();
        cout << r->getType() << ": " << bill << endl;
        total += bill;
    }

    cout << "Total: " << total << endl;

    return 0;
}
