#include <iostream>
#include <limits>
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
            cout << "1. Potential Energy(PE)\n2. Kinetic Energy(KE)\n3. Quit\n";
            cout << "Choice: [1-3] ";
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
                answer = (m * v * v) / 2;
                cout << "KE = ";
                break;
            case 3:
                return;
            default:
                cout << "\nInvalid input\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << answer << "\n";
            return;
        }
    }

    double getInput(char value) {
        double input;

        while (true) {
            if (value == 'm') {
                cout << "Enter the mass of the object in kilograms(kg): ";
            } else if (value == 'v') {
                cout << "Enter the velocity of the object in "
                        "meters/second(m/s): ";
            } else if (value == 'h') {
                cout << "Enter the object's height above a reference point in "
                        "meters(m): ";
            } else {
                cout << "uh what";
            }
            
            if (!(cin >> input)) {
                cout << "Please enter a number\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            return input;
        }

    }
};

int main() {
    // Potential and Kinetic Energy
    EnergyCalculations hi;
    hi.calculate();

    return 0;
}
