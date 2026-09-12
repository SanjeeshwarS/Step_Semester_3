#include <bits/stdc++.h>
using namespace std;

void parseInventoryRecord(string csvLine)
{
    stringstream ss(csvLine);

    string product;
    string sku;
    string quantity;
    string extra;

    getline(ss, product, ',');
    getline(ss, sku, ',');
    getline(ss, quantity, ',');

    if (product.empty() || sku.empty() || quantity.empty())
    {
        cout << "Invalid Record" << endl;
        return;
    }

    if (getline(ss, extra, ','))
    {
        cout << "Invalid Record" << endl;
        return;
    }

    cout << "Product: " << product
         << " | SKU: " << sku
         << " | Qty: " << quantity << endl;
}

int main()
{
    string csvLine;

    cout << "Enter inventory record: ";
    getline(cin, csvLine);

    parseInventoryRecord(csvLine);

    return 0;
}