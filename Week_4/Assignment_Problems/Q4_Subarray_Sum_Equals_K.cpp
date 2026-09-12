#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> nums, int k)
{
    unordered_map<int, int> frequency;

    frequency[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int num : nums)
    {
        currentSum += num;

        int required = currentSum - k;

        if (frequency.find(required) != frequency.end())
        {
            count += frequency[required];
        }

        frequency[currentSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k) << endl;

    return 0;
}