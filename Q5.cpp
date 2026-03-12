#include <iostream>
using namespace std;

class CinemaRow {
private:
    bool* seats;
    int numSeats;

public:
    // Constructor
    CinemaRow(int n) : numSeats(n) {
        seats = new bool[n];
        for (int i = 0; i < n; ++i) {
            seats[i] = false;
        }
    }

    // Book seat
    void bookSeat(int index) {
        if (index < 0 || index >= numSeats) {
            cout << "Error: Seat index " << index << " is out of bounds." << endl;
        } else if (seats[index]) {
            cout << "Error: Seat " << index << " is already booked." << endl;
        } else {
            seats[index] = true;
            cout << "Seat " << index << " booked successfully." << endl;
        }
    }

    // Overload [] operator
    bool operator[](int index) const {
        // Assume index is valid? But we can check? Usually operator[] doesn't do bounds checking, but we can add for safety.
        if (index < 0 || index >= numSeats) {
            cout << "Error: Seat index " << index << " out of bounds in []." << endl;
            return false; // or throw
        }
        return seats[index];
    }

    // Destructor
    ~CinemaRow() {
        delete[] seats;
        cout << "Row memory freed." << endl;
    }
};

// Example usage
int main() {
    CinemaRow row(5);
    row.bookSeat(2);
    row.bookSeat(2);
    row.bookSeat(8);
    cout << "Is seat 2 booked? " << (row[2] ? "Yes" : "No") << endl;
    return 0;
}
