#include <iostream>
#include <limits>
using namespace std;

void getValidNumber(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            return;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Numbers only.\n";
    }
}

int main() {
    int inputChoice;
    double p, m, v;

    cout << "=====================================";
    cout << "\n";
    cout << "MOMENTUM CALCULATOR (p = m * v)\n";
    cout << "=====================================\n";

    do{
        cout << "Choose one of the given:\n";
        cout << "1. Momentum (p)\n";
        cout << "2. Mass (m)\n";
        cout << "3. Velocity (v)\n";
        cout << "Enter your choice (1-3): ";

        cin >> inputChoice;

        // This function checks if the previous input operation failed
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a NUMBER (1-3)\n";
            inputChoice = 0;
        }

        // This one if checks if the input number is out of range
        else if (inputChoice < 1 || inputChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }

    } while (inputChoice < 1 || inputChoice > 3);

    cout << endl;

    switch (inputChoice) {
        case 1:
            getValidNumber("Enter mass (kg): ", m);
            getValidNumber("Enter velocity (m/s): ", v);
            p = m * v;
            cout << "Momentum = " << p << " kg·m/s\n";
            break;

        case 2:
            getValidNumber("Enter momentum (kg·m/s): ", p);
            getValidNumber("Enter velocity (m/s): ", v);
            m = p / v;
            cout << "Mass = " << m << " kg\n";
            break;

        case 3:
            getValidNumber("Enter momentum (kg·m/s): ", p);
            getValidNumber("Enter mass (kg): ", m);
            v = p / m;
            cout << "Velocity = " << v << " m/s\n";
            break;
    }

    return 0;
}


// "My wish? My wish is to fulfill everyone else's wishes. If I can't fulfill them, then send them unto tomorrow." — Phainon of Aedes Elysiae.