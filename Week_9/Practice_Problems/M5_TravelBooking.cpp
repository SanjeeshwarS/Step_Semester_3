#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Booking {
private:
    static constexpr double BOOKING_FEE = 50;

protected:
    double distanceKm;

public:
    Booking(double d) : distanceKm(d) {
    }

    virtual ~Booking() {
    }

    virtual string getMode() const = 0;
    virtual double baseFare() const = 0;

    double total() const {
        return baseFare() + BOOKING_FEE;
    }
};

class BusBooking : public Booking {
public:
    BusBooking(double d) : Booking(d) {
    }

    string getMode() const override {
        return "BUS";
    }

    double baseFare() const override {
        return 2.0 * distanceKm;
    }
};

class TrainBooking : public Booking {
public:
    TrainBooking(double d) : Booking(d) {
    }

    string getMode() const override {
        return "TRAIN";
    }

    double baseFare() const override {
        return 1.5 * distanceKm;
    }
};

class FlightBooking : public Booking {
public:
    FlightBooking(double d) : Booking(d) {
    }

    string getMode() const override {
        return "FLIGHT";
    }

    double baseFare() const override {
        return 2500 + 4.0 * distanceKm;
    }
};

int main() {
    map<string, function<unique_ptr<Booking>(double)>> factory = {
        {"BUS", [](double d) { return unique_ptr<Booking>(new BusBooking(d)); }},
        {"TRAIN", [](double d) { return unique_ptr<Booking>(new TrainBooking(d)); }},
        {"FLIGHT", [](double d) { return unique_ptr<Booking>(new FlightBooking(d)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Booking>> bookings;

    for (int i = 0; i < n; i++) {
        string mode;
        double distance;
        cin >> mode >> distance;
        bookings.push_back(factory[mode](distance));
    }

    cout << fixed << setprecision(2);

    for (const auto& b : bookings) {
        cout << b->getMode() << ": " << b->total() << endl;
    }

    return 0;
}
