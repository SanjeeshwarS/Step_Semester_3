#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}