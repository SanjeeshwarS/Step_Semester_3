#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

// Fees follow the business rules in the problem statement.
// Note: the PDF's sample output (EXPRESS 29.00, INTERNATIONAL 155.00)
// does not match those rules; by the rules they come to 24.00 and 145.00.

class Delivery {
protected:
    double weight;
    double distance;

public:
    Delivery(double w, double d) : weight(w), distance(d) {
    }

    virtual ~Delivery() {
    }

    virtual string getType() const = 0;
    virtual double fee() const = 0;
};

class StandardDelivery : public Delivery {
public:
    StandardDelivery(double w, double d) : Delivery(w, d) {
    }

    string getType() const override {
        return "STANDARD";
    }

    double fee() const override {
        return 5 + 0.50 * weight + 0.10 * distance;
    }
};

class ExpressDelivery : public Delivery {
public:
    ExpressDelivery(double w, double d) : Delivery(w, d) {
    }

    string getType() const override {
        return "EXPRESS";
    }

    double fee() const override {
        return 15 + 1.00 * weight + 0.20 * distance;
    }
};

class InternationalDelivery : public Delivery {
private:
    double customsFee;

public:
    InternationalDelivery(double w, double d, double customs)
        : Delivery(w, d), customsFee(customs) {
    }

    string getType() const override {
        return "INTERNATIONAL";
    }

    double fee() const override {
        return 25 + 2.00 * weight + 0.50 * distance + customsFee;
    }
};

int main() {
    map<string, function<unique_ptr<Delivery>(istream&)>> factory = {
        {"STANDARD", [](istream& in) {
            double w, d;
            in >> w >> d;
            return unique_ptr<Delivery>(new StandardDelivery(w, d));
        }},
        {"EXPRESS", [](istream& in) {
            double w, d;
            in >> w >> d;
            return unique_ptr<Delivery>(new ExpressDelivery(w, d));
        }},
        {"INTERNATIONAL", [](istream& in) {
            double w, d, customs;
            in >> w >> d >> customs;
            return unique_ptr<Delivery>(new InternationalDelivery(w, d, customs));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Delivery>> deliveries;

    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        deliveries.push_back(factory[type](cin));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& d : deliveries) {
        double fee = d->fee();
        cout << d->getType() << ": " << fee << endl;
        total += fee;
    }

    cout << "Total: " << total << endl;

    return 0;
}
