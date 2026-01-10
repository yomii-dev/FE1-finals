#include <iostream>
using namespace std;

// Momentum Calculator. DO NOT USE YET IM STILL FIGURING OUT KUNG PAANO I MAKE SURE
// SA CASE 1,2,3 IS MADE SURE NA IT LOOPS, AND CHECK IF ITS VALID A INPUT

int main() {
    int inputChoice;
    double p, m, v;


    cout << "=====================================";
    cout << "\n";
    cout << "MOMENTUM CALCULATOR (p = m * v)\n";
    cout << "=====================================\n";
    cout << "Choose one of the given:\n";
    cout << "1. Momentum (p)\n";
    cout << "2. Mass (m)\n";
    cout << "3. Velocity (v)\n";
    cout << "Enter your choice of formula (1-3): ";
    cin >> inputChoice;

    cout << endl;


// UNFINISHED PART: Validation for inputChoice

    switch (inputChoice) {
        case 1:
            cout << "Enter mass (kg): ";
            cin >> m;
            cout << "Enter velocity (m/s): ";
            cin >> v;
            p = m * v;
            cout << "Momentum = " << p << " kg·m/s\n";
            break;

        case 2:
            cout << "Enter momentum (kg·m/s): ";
            cin >> p;
            cout << "Enter velocity (m/s): ";
            cin >> v;
            m = p / v;
            cout << "Mass = " << m << " kg\n";
            break;

        case 3:
            cout << "Enter momentum (kg·m/s): ";
            cin >> p;
            cout << "Enter mass (kg): ";
            cin >> m;
            v = p / m;
            cout << "Velocity = " << v << " m/s\n";
            break;

        default:
            cout << "Invalid choice.\n";
    }
    return 0;
}
