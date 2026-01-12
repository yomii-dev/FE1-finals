#include <iostream>
using namespace std;

class EnergyCalculations {
  public:
    void calculate() {
        int choice;
        const double g = 9.81;
        double m;
        double h;
        double v;
        double answer;

        cout << "=== Energy Calculations Calculator :D ===\n";

        while (true) {
            cout << "Which are you looking for?\n";
            cout << "1. Potential Energy(PE)\n2. Kinetic Energy\n";
            cout << "Choice: [1-2] ";
            cin >> choice;

            switch (choice) {
            case 1:
                m = getInput('m');
                h = getInput('h');
                answer = m * g * h;
                cout << "PE = ";
                break;
            case 2:
                m = getInput('m');
                v = getInput('v');
                answer = (m * h) / 2;
                cout << "KE = ";
                break;
            default:
                cout << "I guess you quit the program byee";
                return;
            }
            
            cout << answer << "\n";
            return;
        }
    }

    double getInput(char value) {
        double input;

        if (value == 'm') {
            cout << "Enter the mass of the object in kilograms(kg): ";
            cin >> input;
        } else if (value == 'v') {
            cout << "Enter the velocity of the object in meters/second(m/s): ";
            cin >> input;
        } else if (value == 'h') {
            cout << "Enter the object's height above a reference point in "
                    "meters(m): ";
            cin >> input;
        } else {
            cout << "uh what";
        }

        return input;
    }
};

int main() {
    // Potential and Kinetic Energy
    EnergyCalculations hi;
    hi.calculate();

    return 0;
}
