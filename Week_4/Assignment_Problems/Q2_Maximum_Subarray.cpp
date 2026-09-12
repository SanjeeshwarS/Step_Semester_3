#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> nums)
{
    int currentSum = nums[0];
    int maximumSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currentSum = max(nums[i], currentSum + nums[i]);

        maximumSum = max(maximumSum, currentSum);
    }

    return maximumSum;
}

int main()
{
    vector<int> nums = {
        -2, 1, -3, 4, -1, 2, 1, -5, 4
    };

    cout << maxSubArray(nums) << endl;

    return 0;
}