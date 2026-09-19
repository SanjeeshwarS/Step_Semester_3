#include <iostream>
using namespace std;

class Character {
private:
    int health;
    const int maxHealth;

public:
    Character(int max) : maxHealth(max), health(max) {
    }

    void takeDamage(int amount) {
        health -= amount;

        if (health < 0) {
            health = 0;
        }
    }

    void heal(int amount) {
        health += amount;

        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    int getHealth() const {
        return health;
    }
};

int main() {
    Character c(100);

    c.takeDamage(30);
    cout << "Health after damage: "
         << c.getHealth() << endl;

    c.heal(50);
    cout << "Health after healing: "
         << c.getHealth() << endl;

    c.takeDamage(150);
    cout << "Health after extra damage: "
         << c.getHealth() << endl;

    return 0;
}