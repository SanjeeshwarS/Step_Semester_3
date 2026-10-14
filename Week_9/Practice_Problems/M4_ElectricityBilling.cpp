#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class Connection {
protected:
    int units;

public:
    Connection(int u) : units(u) {
    }

    virtual ~Connection() {
    }

    virtual string getType() const = 0;
    virtual double bill() const = 0;
};

class HomeConnection : public Connection {
public:
    HomeConnection(int u) : Connection(u) {
    }

    string getType() const override {
        return "HOME";
    }

    double bill() const override {
        if (units <= 100) {
            return 5.0 * units;
        }
        return 5.0 * 100 + 7.0 * (units - 100);
    }
};

class ShopConnection : public Connection {
public:
    ShopConnection(int u) : Connection(u) {
    }

    string getType() const override {
        return "SHOP";
    }

    double bill() const override {
        return 8.0 * units + 100;
    }
};

class FactoryConnection : public Connection {
public:
    FactoryConnection(int u) : Connection(u) {
    }

    string getType() const override {
        return "FACTORY";
    }

    double bill() const override {
        return max(6.0 * units, 1000.0);
    }
};

int main() {
    map<string, function<unique_ptr<Connection>(int)>> factory = {
        {"HOME", [](int u) { return unique_ptr<Connection>(new HomeConnection(u)); }},
        {"SHOP", [](int u) { return unique_ptr<Connection>(new ShopConnection(u)); }},
        {"FACTORY", [](int u) { return unique_ptr<Connection>(new FactoryConnection(u)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Connection>> connections;

    for (int i = 0; i < n; i++) {
        string type;
        int units;
        cin >> type >> units;
        connections.push_back(factory[type](units));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& c : connections) {
        double bill = c->bill();
        cout << c->getType() << ": " << bill << endl;
        total += bill;
    }

    cout << "Total: " << total << endl;

    return 0;
}
