#include <iostream>
#include <iomanip>
using namespace std;

class TransitCard {
private:
    double balance;
    bool isActiveTrip;

public:
    // Parameterized constructor
    TransitCard(double initialBalance) : balance(initialBalance), isActiveTrip(false) {}

    // tapIn
    void tapIn() {
        if (isActiveTrip) {
            cout << "Error: Already on an active trip!" << endl;
        } else if (balance < 2.50) {
            cout << "Error: Insufficient balance!" << endl;
        } else {
            isActiveTrip = true;
            cout << "Tap-in successful." << endl;
        }
    }

    // tapOut
    void tapOut() {
        if (!isActiveTrip) {
            cout << "Error: Cannot tap out, no active trip!" << endl;
        } else {
            balance -= 2.50;
            isActiveTrip = false;
            cout << fixed << setprecision(2);
            cout << "Tap-out successful. Remaining balance: $" << balance << endl;
        }
    }

    // Overload = operator for penalty deduction (double)
    TransitCard& operator=(double penalty) {
        balance -= penalty;
        // Note: We don't change trip status? Possibly it's for forgotten tap-out, so maybe set isActiveTrip false? Not specified. We'll just deduct.
        return *this;
    }

    // Overload ! operator
    bool operator!() const {
        return balance == 0.0;
    }

    // Optional: getter for balance if needed
    double getBalance() const { return balance; }
};

// Example usage
int main() {
    TransitCard card(5.00);
    card.tapIn();
    card.tapIn();
    card.tapOut();
    card.tapOut();
    if (!card) {
        cout << "Empty!" << endl;
    }
    return 0;
}
