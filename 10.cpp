#include <iostream>
using namespace std;

class FreeFall {
private:
    double time;          // this is in seconds
    const double g = 9.8; // m/s²

public:
    FreeFall(double t) {
        time = t;
    }

    // calculating velocity
    double velocity() {
        return g * time;
    }

    // calculating the distance during fall
    double distance() {
        return 0.5 * g * time * time;
    }

    // display
    void showResults() {
        cout << "After " << time << " seconds:\n";
        cout << "Velocity = " << velocity() << " m/s\n";
        cout << "Distance fallen = " << distance() << " meters\n";
    }
};

int main() {
    double t;
    cout << "Enter time (in seconds): ";
    cin >> t;

    FreeFall ball(t); // Create an object
    ball.showResults();

    return 0;
}
