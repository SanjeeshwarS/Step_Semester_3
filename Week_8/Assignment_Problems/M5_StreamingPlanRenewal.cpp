#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

struct Date {
    int year;
    int month;
    int day;

    static bool isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    static int daysInMonth(int y, int m) {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeap(y)) {
            return 29;
        }
        return days[m - 1];
    }

    static Date parse(const string& text) {
        Date d;
        char dash;
        stringstream ss(text);
        ss >> d.year >> dash >> d.month >> dash >> d.day;
        return d;
    }

    Date plusDays(int count) const {
        Date d = *this;
        d.day += count;

        while (d.day > daysInMonth(d.year, d.month)) {
            d.day -= daysInMonth(d.year, d.month);
            d.month++;

            if (d.month > 12) {
                d.month = 1;
                d.year++;
            }
        }

        return d;
    }

    string toString() const {
        stringstream ss;
        ss << year << "-"
           << setw(2) << setfill('0') << month << "-"
           << setw(2) << setfill('0') << day;
        return ss.str();
    }
};

class Subscription {
protected:
    string name;
    Date startDate;

public:
    Subscription(string n, Date start) : name(n), startDate(start) {
    }

    virtual ~Subscription() {
    }

    virtual int validityDays() const = 0;

    string getName() const {
        return name;
    }

    Date renewalDate() const {
        return startDate.plusDays(validityDays());
    }
};

class BasicPlan : public Subscription {
public:
    BasicPlan(string n, Date start) : Subscription(n, start) {
    }

    int validityDays() const override {
        return 30;
    }
};

class StandardPlan : public Subscription {
public:
    StandardPlan(string n, Date start) : Subscription(n, start) {
    }

    int validityDays() const override {
        return 90;
    }
};

class PremiumPlan : public Subscription {
public:
    PremiumPlan(string n, Date start) : Subscription(n, start) {
    }

    int validityDays() const override {
        return 365;
    }
};

int main() {
    map<string, function<unique_ptr<Subscription>(string, Date)>> factory = {
        {"BASIC", [](string n, Date d) { return unique_ptr<Subscription>(new BasicPlan(n, d)); }},
        {"STANDARD", [](string n, Date d) { return unique_ptr<Subscription>(new StandardPlan(n, d)); }},
        {"PREMIUM", [](string n, Date d) { return unique_ptr<Subscription>(new PremiumPlan(n, d)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Subscription>> subscribers;

    for (int i = 0; i < n; i++) {
        string plan, name, start;
        cin >> plan >> name >> start;
        subscribers.push_back(factory[plan](name, Date::parse(start)));
    }

    for (const auto& s : subscribers) {
        cout << s->getName() << ": "
             << s->renewalDate().toString() << endl;
    }

    return 0;
}
