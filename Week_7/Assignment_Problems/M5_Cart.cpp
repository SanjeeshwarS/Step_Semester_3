#include <iostream>
using namespace std;

class Cart {
private:
    double* prices;
    int maxItems;
    int itemCount;
    const char* cartId;

public:
    Cart(const char* id, int size)
        : cartId(id) {
        maxItems = size;
        itemCount = 0;
        prices = new double[maxItems];
    }

    void addItem(double price) {
        if (itemCount >= maxItems) {
            cout << "Cart is full" << endl;
            return;
        }

        prices[itemCount] = price;
        itemCount++;
    }

    double getTotal() const {
        double total = 0;

        for (int i = 0; i < itemCount; i++) {
            total += prices[i];
        }

        return total;
    }

    int getItemCount() const {
        return itemCount;
    }

    ~Cart() {
        delete[] prices;
    }
};

int main() {
    Cart cart("CART-5", 20);

    cart.addItem(250);
    cart.addItem(99);
    cart.addItem(151);

    cout << "Total: "
         << cart.getTotal() << endl;

    cout << "Item count: "
         << cart.getItemCount() << endl;

    return 0;
}