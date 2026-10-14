#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class NightService {
public:
    virtual ~NightService() {
    }

    virtual double nightFare(double dayFare) const {
        return dayFare * 1.20;
    }
};

class Cab {
private:
    static constexpr double MINIMUM_FARE = 100;

protected:
    double km;

public:
    Cab(double distance) : km(distance) {
    }

    virtual ~Cab() {
    }

    virtual string getType() const = 0;
    virtual double ratePerKm() const = 0;

    double dayFare() const {
        return max(km * ratePerKm(), MINIMUM_FARE);
    }
};

constexpr double Cab::MINIMUM_FARE;

class MiniCab : public Cab {
public:
    MiniCab(double distance) : Cab(distance) {
    }

    string getType() const override {
        return "MINI";
    }

    double ratePerKm() const override {
        return 10;
    }
};

class SedanCab : public Cab, public NightService {
public:
    SedanCab(double distance) : Cab(distance) {
    }

    string getType() const override {
        return "SEDAN";
    }

    double ratePerKm() const override {
        return 14;
    }
};

class SuvCab : public Cab, public NightService {
public:
    SuvCab(double distance) : Cab(distance) {
    }

    string getType() const override {
        return "SUV";
    }

    double ratePerKm() const override {
        return 18;
    }
};

struct Trip {
    unique_ptr<Cab> cab;
    bool night;
};

int main() {
    map<string, function<unique_ptr<Cab>(double)>> factory = {
        {"MINI", [](double d) { return unique_ptr<Cab>(new MiniCab(d)); }},
        {"SEDAN", [](double d) { return unique_ptr<Cab>(new SedanCab(d)); }},
        {"SUV", [](double d) { return unique_ptr<Cab>(new SuvCab(d)); }}
    };

    int n;
    cin >> n;

    vector<Trip> trips;

    for (int i = 0; i < n; i++) {
        string type, time;
        double km;
        cin >> type >> km >> time;
        trips.push_back({factory[type](km), time == "NIGHT"});
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& trip : trips) {
        const Cab& cab = *trip.cab;
        double fare = cab.dayFare();

        if (trip.night) {
            const NightService* service = dynamic_cast<const NightService*>(&cab);

            if (service == nullptr) {
                cout << cab.getType() << ": night service not available" << endl;
                continue;
            }

            fare = service->nightFare(fare);
        }

        cout << cab.getType() << ": " << fare << endl;
        total += fare;
    }

    cout << "Total: " << total << endl;

    return 0;
}
