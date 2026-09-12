#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices)
{
    int minimumPrice = prices[0];
    int maximumProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - minimumPrice;

        maximumProfit = max(maximumProfit, profit);

        minimumPrice = min(minimumPrice, prices[i]);
    }

    return maximumProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}