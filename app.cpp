#include <cmath>
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

            return;
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

class EnergyCalculations {
  public:
    void run() {
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

            cout << answer << "J\n";
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

class Momentum {
  public:
    void run() {
        int inputChoice;
        double p, m, v;

        cout << "=====================================";
        cout << "\n";
        cout << "MOMENTUM CALCULATOR (p = m * v)\n";
        cout << "=====================================\n";

        do {
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
                cout << "Invalid choice. Please enter a number between 1 and "
                        "3.\n";
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
    }

  private:
    void getValidNumber(const string &prompt, double &value) {
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
};

class ProjectileMotion {
  public:
    void run() {
        char repeat;

        cout << "\n=== Projectile Motion Calculator ===\n";

        while (true) {
            int choice = _pickVariable();
            double velocity = _takeVelocity();
            double angle = _takeAngle();

            _solve(choice, velocity, angle);

            cout << "\nCalculate another projectile problem? [y/n] ";
            cin >> repeat;

            if (repeat == 'n' || repeat == 'N') {
                return;
            }
        }
    }

  private:
    const double g = 9.81;

    int _pickVariable() {
        int choice;

        while (true) {
            cout << "\nSolve for:\n";
            cout << "1. Time of Flight\n";
            cout << "2. Maximum Height\n";
            cout << "3. Range\n";
            cout << "Choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice.\n";
                continue;
            }

            return choice;
        }
    }

    double _takeVelocity() {
        double v;

        while (true) {
            cout << "Enter initial velocity (m/s): ";
            cin >> v;

            if (cin.fail() || v <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Velocity must be positive.\n";
                continue;
            }

            return v;
        }
    }

    double _takeAngle() {
        double a;

        while (true) {
            cout << "Enter launch angle (degrees): ";
            cin >> a;

            if (cin.fail() || a <= 0 || a >= 90) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Angle must be between 0 and 90.\n";
                continue;
            }

            return a;
        }
    }

    void _solve(int choice, double v, double angleDeg) {
        double angleRad = angleDeg * (M_PI / 180.0);

        if (choice == 1) {
            cout << "Time of Flight: " << (2 * v * sin(angleRad)) / g << " s\n";
        } else if (choice == 2) {
            cout << "Maximum Height: " << pow(v * sin(angleRad), 2) / (2 * g)
                 << " m\n";
        } else if (choice == 3) {
            cout << "Range: " << (pow(v, 2) * sin(2 * angleRad)) / g << " m\n";
        }
    }
};

class GravitationalForceCalculator {
  private:
    const double g = 6.67e-11; // Gravitational constant

    // Method to calculate gravitational force
    double calculateForce(int mass1, int mass2, int distance) {
        return (g * mass1 * mass2) / (distance * distance);
    }

  public:
    void run() {
        cout << "Calculate Gravitational Force\n";
        int mass1, mass2, distance;
        cout << "Enter Mass 1 in kg: ";
        cin >> mass1;
        cout << "Enter Mass 2 in kg: ";
        cin >> mass2;
        cout << "Enter Distance in meters: ";
        cin >> distance;

        double force = calculateForce(mass1, mass2, distance);
        cout << "Gravitational Force: " << force << " N\n\n";
    }
};

class Temperature {
  public:
    void run() {
        char repeat;
        cout << "=== Temperature Conversion Calculator :D ===\n";
        while (true) {
            double tempValue = _takeValue();
            char initialUnit = _takeInitialUnit();
            char convertedUnit = _takeConvertedUnit();

            double answer = _solve(tempValue, initialUnit, convertedUnit);

            cout << tempValue << initialUnit << " -> " << answer
                 << convertedUnit;

            cout << "\nDo you wish convert more? [y/n] ";
            cin >> repeat;

            if (repeat == 'n' || repeat == 'N') {
                return;
            }
        }
    }

    /* Underscore naming conversion para di accidentally used */
  private:
    double _takeValue() {
        while (true) {
            double temp;

            cout << "1. Input the VALUE of the temperature: ";

            if (!(cin >> temp)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter only real numbers\n";
                continue;
            }

            return temp;
        }
    }

    char _takeInitialUnit() {
        char unit;

        while (true) {
            cout << "2. Pick the unit that your temperature IS IN [F/C/K]: ";
            if (!(cin >> unit)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid input...\n";
                continue;
            }

            /* This basically leaves only the first char */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!_isValidUnit(unit)) {
                cout << "Please input a valid unit [F/C/K].\n";
                continue;
            }

            unit = toupper(unit);
            return unit;
        }
    }

    char _takeConvertedUnit() {
        char unit;

        while (true) {
            cout << "3. Pick the unit that you want to convert TO [F/C/K]: ";
            if (!(cin >> unit)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid input...\n";
                continue;
            }

            /* This basically leaves only the first char */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!_isValidUnit(unit)) {
                cout << "Please input a valid unit [F/C/K].\n";
                continue;
            }

            unit = toupper(unit);
            return unit;
        }
    }

    bool _isValidUnit(char input) {
        char validUnits[6] = {'F', 'C', 'K', 'f', 'c', 'k'};

        for (int i = 0; i < 6; i++) {
            if (input == validUnits[i]) {
                return true;
            }
        }

        return false;
    }

    double _solve(double temp, char initialUnit, char convertedUnit) {
        bool fahrenheitToCelsius = (initialUnit == 'F' && convertedUnit == 'C');
        bool fahrenheitToKelvin = (initialUnit == 'F' && convertedUnit == 'K');
        bool celsiusToFahrenheit = (initialUnit == 'C' && convertedUnit == 'F');
        bool celsiusToKelvin = (initialUnit == 'C' && convertedUnit == 'K');
        bool kelvinToFahrenheit = (initialUnit == 'K' && convertedUnit == 'F');
        bool kelvinToCelsius = (initialUnit == 'K' && convertedUnit == 'C');

        // if they, for some reason, picked the same unit to convert to
        if (initialUnit == convertedUnit) {
            cout << "You do realize that you converted it to the same unit "
                    "right?\n";
            return temp;
        } else if (fahrenheitToCelsius) {
            return ((temp - 32) / 1.8); // F -> C
        } else if (fahrenheitToKelvin) {
            return ((temp - 32) / 1.8) + 273.15; // F -> K
        } else if (celsiusToFahrenheit) {
            return (temp * 1.8) + 32; // C -> F
        } else if (celsiusToKelvin) {
            return temp + 273.15; // C -> K
        } else if (kelvinToFahrenheit) {
            return ((temp - 273.15) * 1.8) + 32; // K -> F
        } else if (kelvinToCelsius) {
            return temp - 273.15; // K -> C
        } else {
            cout << "How tf did you get here???\n";
            return -1;
        }
    }
};

class Menu {
  private:
    /* Class Initializations dito */
    UnitConversion wan;
    OhmsLaw too;
    EnergyCalculations tree;
    Momentum fore;
    ProjectileMotion payb;
    GravitationalForceCalculator six;
    Temperature seben;
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
                tree.run();
                break;
            case 4:
                // Call ung calc nung choice
                fore.run();
                break;
            case 5:
                // Call ung calc nung choice
                payb.run();
                break;
            case 6:
                // Call ung calc nung choice
                six.run();
                break;
            case 7:
                // Call ung calc nung choice
                seben.run();
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
