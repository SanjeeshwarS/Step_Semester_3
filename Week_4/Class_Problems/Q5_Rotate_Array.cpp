#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> nums, int k)
{
    int n = nums.size();

    k = k % n;

    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;

        result[newIndex] = nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {
        1, 2, 3, 4, 5, 6, 7
    };

    int k = 3;

    vector<int> result = rotateArray(nums, k);

    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}