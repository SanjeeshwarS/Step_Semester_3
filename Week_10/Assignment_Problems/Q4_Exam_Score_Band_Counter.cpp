#include <iostream>
#include <vector>
using namespace std;

// Linear scan: O(n) time per query, O(1) space.
// Binary search: O(log n) time per query, O(1) space.
// Duplicates at the edges mean a plain binary search (which stops at any match)
// is not enough: we need the FIRST index with score >= low and the FIRST index
// with score > high, so every copy of low and high falls inside the range.

int firstIndexAtLeast(const vector<int>& scores, int target) {
    int left = 0;
    int right = scores.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (scores[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int firstIndexGreaterThan(const vector<int>& scores, int target) {
    int left = 0;
    int right = scores.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (scores[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int countInBand(const vector<int>& scores, int low, int high) {
    return firstIndexGreaterThan(scores, high) - firstIndexAtLeast(scores, low);
}

int main() {
    vector<int> scores = {35, 42, 42, 50, 58, 58, 58, 63, 71, 88};

    cout << countInBand(scores, 42, 58) << endl;
    cout << countInBand(scores, 90, 100) << endl;

    return 0;
}
