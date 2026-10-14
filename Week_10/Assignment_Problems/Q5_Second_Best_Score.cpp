#include <iostream>
#include <vector>
using namespace std;

// Time: O(n) -- one pass, compared with O(n log n) for sorting first.
// Space: O(1) extra -- sorting would also need to copy or modify the array.

int secondHighest(const vector<int>& scores) {
    int highest = -1;
    int second = -1;

    for (int score : scores) {
        if (score > highest) {
            second = highest;
            highest = score;
        } else if (score < highest && score > second) {
            second = score;
        }
    }

    return second;
}

int main() {
    cout << secondHighest({45, 78, 92, 78, 60}) << endl;
    cout << secondHighest({50, 50, 50}) << endl;

    return 0;
}
