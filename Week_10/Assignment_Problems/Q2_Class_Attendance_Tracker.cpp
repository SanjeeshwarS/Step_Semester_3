#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Time: O(n) -- both answers are found in a single pass.
// Space: O(1) extra.

pair<int, int> attendanceSummary(const vector<int>& days) {
    int present = 0;
    int currentStreak = 0;
    int longestStreak = 0;

    for (int day : days) {
        if (day == 1) {
            present++;
            currentStreak++;
            longestStreak = max(longestStreak, currentStreak);
        } else {
            currentStreak = 0;
        }
    }

    return {present, longestStreak};
}

void printSummary(const vector<int>& days) {
    pair<int, int> summary = attendanceSummary(days);

    cout << "Present: " << summary.first
         << ", Longest streak: " << summary.second << endl;
}

int main() {
    printSummary({1, 1, 0, 1, 1, 1, 0, 1});
    printSummary({0, 0, 0});

    return 0;
}
