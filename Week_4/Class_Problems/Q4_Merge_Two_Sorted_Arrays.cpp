#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
        }
        else
        {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main()
{
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    vector<int> result = mergeSortedArrays(arr1, arr2);

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