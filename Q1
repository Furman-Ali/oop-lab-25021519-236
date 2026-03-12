#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    double currentWeight;
    const double maxWeight; // fixed at 500.0

public:
    // Parameterized constructor with default values
    Elevator(int floor = 1, double weight = 0.0) : currentFloor(floor), currentWeight(weight), maxWeight(500.0) {
        // No need to print anything
    }

    // Chainable loadPassenger
    Elevator& loadPassenger(double weight) {
        if (currentWeight + weight > maxWeight) {
            cout << "Error: Weight exceeds " << maxWeight << "kg. Passenger rejected." << endl;
        } else {
            currentWeight += weight;
        }
        return *this;
    }

    // Chainable goToFloor
    Elevator& goToFloor(int floor) {
        if (floor < 1 || floor > 10) {
            cout << "Error: Floor " << floor << " is out of bounds." << endl;
        } else {
            currentFloor = floor;
        }
        return *this;
    }

    // Overload == operator
    bool operator==(const Elevator& other) const {
        return currentFloor == other.currentFloor;
    }

    // Destructor
    ~Elevator() {
        cout << "Elevator powering down at floor " << currentFloor << endl;
    }
};

// Example usage (not part of required code, but for testing)
int main() {
    Elevator el(1, 0);
    el.loadPassenger(400.0).loadPassenger(150.0).goToFloor(5).goToFloor(12);
    return 0;
}
