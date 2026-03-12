#include <iostream>
using namespace std;

class EspressoMachine {
private:
    int waterLevel;
    int coffeeBeans;
    int id;
    static int nextId; // static to assign unique ids

public:
    // Parameterized constructor
    EspressoMachine(int water, int beans) : waterLevel(water), coffeeBeans(beans) {
        id = nextId++;
    }

    // Brew method
    void brew() {
        if (waterLevel >= 30 && coffeeBeans >= 10) {
            waterLevel -= 30;
            coffeeBeans -= 10;
            cout << "Brew successful. Remaining -> Water: " << waterLevel << "ml, Beans: " << coffeeBeans << "g" << endl;
        } else {
            cout << "Refill needed. Cannot brew." << endl;
        }
    }

    // Overload + operator
    EspressoMachine operator+(const EspressoMachine& other) const {
        return EspressoMachine(waterLevel + other.waterLevel, coffeeBeans + other.coffeeBeans);
    }

    // Destructor
    ~EspressoMachine() {
        cout << "Machine " << id << " shutting down." << endl;
    }
};

// Initialize static member
int EspressoMachine::nextId = 1;

// Example usage
int main() {
    EspressoMachine m1(20, 5);
    EspressoMachine m2(20, 10);
    m1.brew();
    EspressoMachine m3 = m1 + m2;
    m3.brew();
    return 0;
}
