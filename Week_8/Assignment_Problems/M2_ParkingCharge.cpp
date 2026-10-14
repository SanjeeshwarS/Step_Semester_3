#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    int hours;

public:
    Vehicle(int h) : hours(h) {
    }

    virtual ~Vehicle() {
    }

    virtual string getType() const = 0;
    virtual double charge() const = 0;
};

class Bike : public Vehicle {
public:
    Bike(int h) : Vehicle(h) {
    }

    string getType() const override {
        return "BIKE";
    }

    double charge() const override {
        return 10.0 * hours;
    }
};

class Car : public Vehicle {
public:
    Car(int h) : Vehicle(h) {
    }

    string getType() const override {
        return "CAR";
    }

    double charge() const override {
        return 30.0 + 20.0 * (hours - 1);
    }
};

class Truck : public Vehicle {
public:
    Truck(int h) : Vehicle(h) {
    }

    string getType() const override {
        return "TRUCK";
    }

    double charge() const override {
        return max(50.0 * hours, 100.0);
    }
};

int main() {
    map<string, function<unique_ptr<Vehicle>(int)>> factory = {
        {"BIKE", [](int h) { return unique_ptr<Vehicle>(new Bike(h)); }},
        {"CAR", [](int h) { return unique_ptr<Vehicle>(new Car(h)); }},
        {"TRUCK", [](int h) { return unique_ptr<Vehicle>(new Truck(h)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Vehicle>> vehicles;

    for (int i = 0; i < n; i++) {
        string type;
        int hours;
        cin >> type >> hours;
        vehicles.push_back(factory[type](hours));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& v : vehicles) {
        double charge = v->charge();
        cout << v->getType() << ": " << charge << endl;
        total += charge;
    }

    cout << "Total: " << total << endl;

    return 0;
}
