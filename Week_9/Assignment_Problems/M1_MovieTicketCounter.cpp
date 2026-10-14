#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class Ticket {
private:
    static constexpr double CONVENIENCE_FEE = 20;

protected:
    int count;

public:
    Ticket(int c) : count(c) {
    }

    virtual ~Ticket() {
    }

    virtual string getSeatType() const = 0;
    virtual double pricePerTicket() const = 0;

    double amount() const {
        return count * (pricePerTicket() + CONVENIENCE_FEE);
    }
};

class RegularTicket : public Ticket {
public:
    RegularTicket(int c) : Ticket(c) {
    }

    string getSeatType() const override {
        return "REGULAR";
    }

    double pricePerTicket() const override {
        return 150;
    }
};

class PremiumTicket : public Ticket {
public:
    PremiumTicket(int c) : Ticket(c) {
    }

    string getSeatType() const override {
        return "PREMIUM";
    }

    double pricePerTicket() const override {
        return 250;
    }
};

class ReclinerTicket : public Ticket {
public:
    ReclinerTicket(int c) : Ticket(c) {
    }

    string getSeatType() const override {
        return "RECLINER";
    }

    double pricePerTicket() const override {
        return 400;
    }
};

int main() {
    map<string, function<unique_ptr<Ticket>(int)>> factory = {
        {"REGULAR", [](int c) { return unique_ptr<Ticket>(new RegularTicket(c)); }},
        {"PREMIUM", [](int c) { return unique_ptr<Ticket>(new PremiumTicket(c)); }},
        {"RECLINER", [](int c) { return unique_ptr<Ticket>(new ReclinerTicket(c)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Ticket>> bookings;

    for (int i = 0; i < n; i++) {
        string seat;
        int count;
        cin >> seat >> count;
        bookings.push_back(factory[seat](count));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& b : bookings) {
        double amount = b->amount();
        cout << b->getSeatType() << ": " << amount << endl;
        total += amount;
    }

    cout << "Total: " << total << endl;

    return 0;
}
