#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Insurable {
public:
    virtual ~Insurable() {
    }

    virtual double insurance() const = 0;
};

class Parcel {
protected:
    double weightKg;
    double declaredValue;

public:
    Parcel(double w, double value) : weightKg(w), declaredValue(value) {
    }

    virtual ~Parcel() {
    }

    virtual string getType() const = 0;
    virtual double shippingCharge() const = 0;
};

class StandardParcel : public Parcel {
public:
    StandardParcel(double w, double value) : Parcel(w, value) {
    }

    string getType() const override {
        return "STANDARD";
    }

    double shippingCharge() const override {
        return 40 + 10 * weightKg;
    }
};

class ExpressParcel : public Parcel, public Insurable {
public:
    ExpressParcel(double w, double value) : Parcel(w, value) {
    }

    string getType() const override {
        return "EXPRESS";
    }

    double shippingCharge() const override {
        return 80 + 15 * weightKg;
    }

    double insurance() const override {
        return declaredValue * 0.02;
    }
};

class FragileParcel : public StandardParcel, public Insurable {
public:
    FragileParcel(double w, double value) : StandardParcel(w, value) {
    }

    string getType() const override {
        return "FRAGILE";
    }

    double shippingCharge() const override {
        return StandardParcel::shippingCharge() + 50;
    }

    double insurance() const override {
        return declaredValue * 0.02;
    }
};

int main() {
    map<string, function<unique_ptr<Parcel>(double, double)>> factory = {
        {"STANDARD", [](double w, double v) { return unique_ptr<Parcel>(new StandardParcel(w, v)); }},
        {"EXPRESS", [](double w, double v) { return unique_ptr<Parcel>(new ExpressParcel(w, v)); }},
        {"FRAGILE", [](double w, double v) { return unique_ptr<Parcel>(new FragileParcel(w, v)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Parcel>> parcels;

    for (int i = 0; i < n; i++) {
        string type;
        double weight, value;
        cin >> type >> weight >> value;
        parcels.push_back(factory[type](weight, value));
    }

    double grandTotal = 0;
    cout << fixed << setprecision(2);

    for (const auto& p : parcels) {
        double charge = p->shippingCharge();
        double insurance = 0;

        const Insurable* insurable = dynamic_cast<const Insurable*>(p.get());
        if (insurable != nullptr) {
            insurance = insurable->insurance();
        }

        double total = charge + insurance;

        cout << p->getType() << ": Charge=" << charge
             << " Insurance=" << insurance
             << " Total=" << total << endl;

        grandTotal += total;
    }

    cout << "Grand Total: " << grandTotal << endl;

    return 0;
}
