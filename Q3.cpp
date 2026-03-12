#include <iostream>
using namespace std;

class DigitalPet {
private:
    int hunger;
    int energy;

    // Helper to clamp values
    void clampHunger() {
        if (hunger < 0) {
            hunger = 0;
            cout << "Hunger is bounded at 0." << endl;
        } else if (hunger > 100) {
            hunger = 100;
            cout << "Hunger is bounded at 100." << endl;
        }
    }

    void clampEnergy() {
        if (energy < 0) {
            energy = 0;
            cout << "Energy is bounded at 0." << endl;
        } else if (energy > 100) {
            energy = 100;
            cout << "Energy is bounded at 100." << endl;
        }
    }

public:
    // Parameterized constructor
    DigitalPet(int h, int e) : hunger(h), energy(e) {
        // Ensure initial values are within bounds? Not specified, but we could clamp.
        clampHunger();
        clampEnergy();
    }

    // Chainable feed
    DigitalPet& feed() {
        hunger -= 20;
        clampHunger();
        return *this;
    }

    // Chainable sleep
    DigitalPet& sleep() {
        energy += 30;
        clampEnergy();
        return *this;
    }

    // Prefix ++
    DigitalPet& operator++() {
        energy -= 10;
        hunger += 10;
        // Clamp both
        clampEnergy();
        clampHunger();
        return *this;
    }

    // Postfix ++
    DigitalPet operator++(int) {
        DigitalPet temp = *this; // save original
        ++(*this); // use prefix
        return temp;
    }

    // Print stats
    void printStats() const {
        cout << "Current Stats -> Hunger: " << hunger << ", Energy: " << energy << endl;
    }
};

// Example usage
int main() {
    DigitalPet pet(10, 90);
    pet.feed().sleep();
    pet.printStats();
    return 0;
}
