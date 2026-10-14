#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class SaverMode {
public:
    virtual ~SaverMode() {
    }

    virtual double saverUnits(double normalUnits) const {
        return normalUnits * 0.75;
    }
};

class Appliance {
private:
    static constexpr double COST_PER_UNIT = 8;

protected:
    double hours;

public:
    Appliance(double h) : hours(h) {
    }

    virtual ~Appliance() {
    }

    virtual string getName() const = 0;
    virtual double powerWatts() const = 0;

    double units() const {
        return powerWatts() * hours / 1000;
    }

    static double cost(double units) {
        return units * COST_PER_UNIT;
    }
};

class Fridge : public Appliance {
public:
    Fridge(double h) : Appliance(h) {
    }

    string getName() const override {
        return "FRIDGE";
    }

    double powerWatts() const override {
        return 150;
    }
};

class AirConditioner : public Appliance, public SaverMode {
public:
    AirConditioner(double h) : Appliance(h) {
    }

    string getName() const override {
        return "AC";
    }

    double powerWatts() const override {
        return 1500;
    }
};

class Television : public Appliance {
public:
    Television(double h) : Appliance(h) {
    }

    string getName() const override {
        return "TV";
    }

    double powerWatts() const override {
        return 100;
    }
};

class WashingMachine : public Appliance, public SaverMode {
public:
    WashingMachine(double h) : Appliance(h) {
    }

    string getName() const override {
        return "WASHER";
    }

    double powerWatts() const override {
        return 500;
    }
};

struct Usage {
    unique_ptr<Appliance> appliance;
    bool saver;
};

int main() {
    map<string, function<unique_ptr<Appliance>(double)>> factory = {
        {"FRIDGE", [](double h) { return unique_ptr<Appliance>(new Fridge(h)); }},
        {"AC", [](double h) { return unique_ptr<Appliance>(new AirConditioner(h)); }},
        {"TV", [](double h) { return unique_ptr<Appliance>(new Television(h)); }},
        {"WASHER", [](double h) { return unique_ptr<Appliance>(new WashingMachine(h)); }}
    };

    int n;
    cin >> n;

    string line;
    getline(cin, line);

    vector<Usage> usages;

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);

        string name, mode;
        double hours;
        ss >> name >> hours >> mode;

        usages.push_back({factory[name](hours), mode == "SAVER"});
    }

    double totalCost = 0;
    cout << fixed << setprecision(2);

    for (const auto& usage : usages) {
        const Appliance& appliance = *usage.appliance;
        double units = appliance.units();

        if (usage.saver) {
            const SaverMode* saver = dynamic_cast<const SaverMode*>(&appliance);

            if (saver == nullptr) {
                cout << appliance.getName() << ": saver mode not supported" << endl;
                continue;
            }

            units = saver->saverUnits(units);
        }

        double cost = Appliance::cost(units);

        cout << appliance.getName() << ": Units=" << units
             << " Cost=" << cost << endl;

        totalCost += cost;
    }

    cout << "Total Cost: " << totalCost << endl;

    return 0;
}
