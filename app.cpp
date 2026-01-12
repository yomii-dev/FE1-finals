#include <iostream>
#include <limits>
#include <string>
using namespace std;

class UnitConversion {
  private:
    int inputChoice;
    double input, result;
    string unit;
    char repeat;

  public:
    void run() {
        while (true) {
            cout << "\n=== UNIT CONVERSION CALCULATOR ===\n";
            cout << "1. Meters to Kilometers\n";
            cout << "2. Meters to Miles\n";
            cout << "3. Kilometers to Miles\n";
            cout << "4. Kilometers to Meters\n";
            cout << "5. Miles to Kilometers\n";
            cout << "6. Miles to Meters\n";
            cout << "7. Seconds to Minutes\n";
            cout << "8. Seconds to Hours\n";
            cout << "9. Seconds to Days\n";
            cout << "10. Minutes to Seconds\n";
            cout << "11. Hours to Seconds\n";
            cout << "12. Days to Seconds\n";
            cout << "13. m/s to km/h\n";
            cout << "14. m/s^2 to km/h^2\n";
            cout << "Choose an option (1–14): ";

            cin >> inputChoice;

            // Not gonna lie, I asked ChatGPT for help with this part
            if (cin.fail() || inputChoice < 1 || inputChoice > 14) {
                cout << "\nTHIS OPTION IS INVALID, TRY AGAIN!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Enter the Value: ";
            while (!(cin >> input)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            // Until here :skyrim_skeleton:

            switch (inputChoice) {
            case 1:
                result = input / 1000;
                unit = " km";
                break;
            case 2:
                result = input / 1609.34;
                unit = " mi";
                break;
            case 3:
                result = input * 0.621371;
                unit = " mi";
                break;
            case 4:
                result = input * 1000;
                unit = " m";
                break;
            case 5:
                result = input * 1.60934;
                unit = " km";
                break;
            case 6:
                result = input * 1609.34;
                unit = " m";
                break;
            case 7:
                result = input / 60;
                unit = " min";
                break;
            case 8:
                result = input / 3600;
                unit = " h";
                break;
            case 9:
                result = input / 86400;
                unit = " days";
                break;
            case 10:
                result = input * 60;
                unit = " s";
                break;
            case 11:
                result = input * 3600;
                unit = " s";
                break;
            case 12:
                result = input * 86400;
                unit = " s";
                break;
            case 13:
                result = input * 3.6;
                unit = " km/h";
                break;
            case 14:
                result = input * 12960;
                unit = " km/h^2";
                break;
            }

            cout << "Result: " << result << unit << '\n';

            cout << "Do you want to convert again?";
            while (!(cin >> repeat)) {
                cout << "Enter a valid input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (repeat == 'y' || repeat == 'Y') {
                continue;
            } else {
                return;
            }
        }
    }
};

class OhmsLaw {
  private:
    double getVoltage(double i, double r) { return i * r; }

    double getCurrent(double v, double r) { return v / r; }

    double getResistance(double v, double i) { return v / i; }

  public:
    void run() {
        double v = 0; // Voltage
        double i = 0; // Current
        double r = 0; // Resistance
        int choice;

        cout << "Welcome to Ohm's Law Calculator!";
        cout << "\n\nPick an Operation:";
        cout << "\n1 Voltage";
        cout << "\n2 Current";
        cout << "\n3 Resistance";
        cout << "\nEnter Operation Number: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value of Current: ";
            while (!(cin >> i)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter the value of Resistance: ";
            while (!(cin >> r)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << i << " * " << r << " = " << getVoltage(i, r) << "V";
            break;

        case 2:
            cout << "Enter the value of Voltage: ";
            while (!(cin >> v)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter the value of Resistance: ";
            while (!(cin >> r)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << v << " / " << r << " = " << getCurrent(v, r) << "A";

            break;

        case 3:
            cout << "Enter the value of Voltage: ";
            while (!(cin >> v)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter the value of Current: ";
            while (!(cin >> i)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << v << " / " << i << " = " << getResistance(v, i) << "Ω";

            break;

        default:
            cout << "Invalid Operation";
        }
        cout << '\n';
    }
};

class Menu {
  private:
    /* Class Initializations dito */
    UnitConversion wan;
    OhmsLaw too;
    bool running = true;
    int choice;

  public:
    void showMenu() {
        while (running) {
            cout << "--- CHOOSE A CALCULATOR ---\n";
            cout << "1. Unit Conversion\n";
            cout << "2. Kinematic Equations for Motion\n";
            cout << "3. Potential and Kinetic Energy\n";
            cout << "4. Momentum\n";
            cout << "5. Projectile Motion\n";
            cout << "6. Gravitational Force\n";
            cout << "7. Temperature Conversion\n";
            cout << "8. Pressure and Volume Calculations\n";
            cout << "9. Find the Time\n";
            cout << "10. Freefall\n";
            cout << "11. Quit\n\n";

            cout << "Choose the number of the calculator to begin: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // Call ung calc nung choice
                wan.run();
                break;
            case 2:
                // Call ung calc nung choice
                too.run();
                break;
            case 3:
                // Call ung calc nung choice

                break;
            case 4:
                // Call ung calc nung choice

                break;
            case 5:
                // Call ung calc nung choice

                break;
            case 6:
                // Call ung calc nung choice

                break;
            case 7:
                // Call ung calc nung choice

                break;
            case 8:
                // Call ung calc nung choice

                break;
            case 9:
                // Call ung calc nung choice

                break;
            case 10:
                // Call ung calc nung choice

                break;
            case 11:
                return;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input.\n\n";
                break;
            }
        }
    }
};

int main() {
    Menu app;
    app.showMenu();

    return 0;
}
