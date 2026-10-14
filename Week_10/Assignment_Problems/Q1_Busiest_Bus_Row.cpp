#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Time: O(r * c) -- every seat is visited once.
// Space: O(1) extra -- only the running sum and the best row are stored.

pair<int, int> busiestRow(const vector<vector<int>>& grid) {
    int bestRow = 0;
    int bestTotal = -1;

    for (size_t row = 0; row < grid.size(); row++) {
        int total = 0;

        for (int seat : grid[row]) {
            total += seat;
        }

        if (total > bestTotal) {
            bestTotal = total;
            bestRow = row;
        }
    }

    return {bestRow, bestTotal};
}

int main() {
    vector<vector<int>> grid = {
        {2, 0, 1},
        {3, 3, 1},
        {1, 1, 1}
    };

    pair<int, int> result = busiestRow(grid);

    cout << "Row " << result.first << ", Total " << result.second << endl;

    return 0;
}
