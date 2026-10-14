#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class Journey {
protected:
    double distance;

public:
    Journey(double d) : distance(d) {
    }

    virtual ~Journey() {
    }

    virtual string getType() const = 0;
    virtual double fare() const = 0;
};

class BusJourney : public Journey {
public:
    BusJourney(double d) : Journey(d) {
    }

    string getType() const override {
        return "BUS";
    }

    double fare() const override {
        return min(2 + 0.10 * distance, 10.0);
    }
};

class TrainJourney : public Journey {
public:
    TrainJourney(double d) : Journey(d) {
    }

    string getType() const override {
        return "TRAIN";
    }

    double fare() const override {
        return 3 + 0.15 * distance;
    }
};

class MetroJourney : public Journey {
private:
    double peakHourFactor;

public:
    MetroJourney(double d, double factor) : Journey(d), peakHourFactor(factor) {
    }

    string getType() const override {
        return "METRO";
    }

    double fare() const override {
        return (1.50 + 0.20 * distance) * peakHourFactor;
    }
};

int main() {
    map<string, function<unique_ptr<Journey>(istream&)>> factory = {
        {"BUS", [](istream& in) {
            double d;
            in >> d;
            return unique_ptr<Journey>(new BusJourney(d));
        }},
        {"TRAIN", [](istream& in) {
            double d;
            in >> d;
            return unique_ptr<Journey>(new TrainJourney(d));
        }},
        {"METRO", [](istream& in) {
            double d, factor;
            in >> d >> factor;
            return unique_ptr<Journey>(new MetroJourney(d, factor));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Journey>> journeys;

    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        journeys.push_back(factory[type](cin));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& j : journeys) {
        double fare = j->fare();
        cout << j->getType() << ": " << fare << endl;
        total += fare;
    }

    cout << "Total: " << total << endl;

    return 0;
}
