#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Time: O(n) -- each name is placed once, whatever the value of k.
// Space: O(n) for the rotated roster.
// Rotating one place at a time, k times, costs O(n * k); with k up to 10^9
// that is billions of moves, while k % n removes every full turn first.

vector<string> rotateRoster(const vector<string>& names, long long k) {
    int n = names.size();
    int shift = k % n;

    vector<string> rotated(n);

    for (int i = 0; i < n; i++) {
        rotated[(i + shift) % n] = names[i];
    }

    return rotated;
}

void printRoster(const vector<string>& names) {
    cout << "[";

    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i];

        if (i != names.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {
    vector<string> names = {"A", "B", "C", "D", "E"};

    printRoster(rotateRoster(names, 2));
    printRoster(rotateRoster(names, 7));

    return 0;
}
