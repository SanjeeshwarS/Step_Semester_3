#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <cmath>
using namespace std;

class Plot {
protected:
    string owner;

public:
    Plot(string o) : owner(o) {
    }

    virtual ~Plot() {
    }

    string getOwner() const {
        return owner;
    }

    virtual string getShape() const = 0;
    virtual double area() const = 0;
};

class CirclePlot : public Plot {
private:
    double radius;

public:
    CirclePlot(string o, double r) : Plot(o), radius(r) {
    }

    string getShape() const override {
        return "CIRCLE";
    }

    double area() const override {
        const double PI = acos(-1.0);
        return PI * radius * radius;
    }
};

class RectanglePlot : public Plot {
private:
    double length;
    double width;

public:
    RectanglePlot(string o, double l, double w) : Plot(o), length(l), width(w) {
    }

    string getShape() const override {
        return "RECTANGLE";
    }

    double area() const override {
        return length * width;
    }
};

class TrianglePlot : public Plot {
private:
    double base;
    double height;

public:
    TrianglePlot(string o, double b, double h) : Plot(o), base(b), height(h) {
    }

    string getShape() const override {
        return "TRIANGLE";
    }

    double area() const override {
        return 0.5 * base * height;
    }
};

void printReport(const vector<unique_ptr<Plot>>& plots) {
    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& p : plots) {
        double area = p->area();
        cout << p->getOwner() << " (" << p->getShape() << "): " << area << endl;
        total += area;
    }

    cout << "Total Area: " << total << endl;
}

int main() {
    map<string, function<unique_ptr<Plot>(string, istream&)>> factory = {
        {"CIRCLE", [](string o, istream& in) {
            double r;
            in >> r;
            return unique_ptr<Plot>(new CirclePlot(o, r));
        }},
        {"RECTANGLE", [](string o, istream& in) {
            double l, w;
            in >> l >> w;
            return unique_ptr<Plot>(new RectanglePlot(o, l, w));
        }},
        {"TRIANGLE", [](string o, istream& in) {
            double b, h;
            in >> b >> h;
            return unique_ptr<Plot>(new TrianglePlot(o, b, h));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Plot>> plots;

    for (int i = 0; i < n; i++) {
        string shape, owner;
        cin >> shape >> owner;
        plots.push_back(factory[shape](owner, cin));
    }

    printReport(plots);

    return 0;
}
