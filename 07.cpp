#include <cctype>
#include <iostream>
#include <limits>
using namespace std;

class Temperature {
  public:
    void convertTemp() {
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
            return ((temp - 32) / 1.8);             // F -> C
        } else if (fahrenheitToKelvin) {
            return ((temp - 32) / 1.8) + 273.15;    // F -> K
        } else if (celsiusToFahrenheit) {
            return (temp * 1.8) + 32;               // C -> F
        } else if (celsiusToKelvin) {
            return temp + 273.15;                   // C -> K
        } else if (kelvinToFahrenheit) {
            return ((temp - 273.15) * 1.8) + 32;    // K -> F
        } else if (kelvinToCelsius) {
            return temp - 273.15;                   // K -> C
        } else {
            cout << "How tf did you get here???\n";
            return -1;
        }
    }
};

int main() {
    // Temperature Conversion - Glen THE 2nd
    Temperature lol;
    lol.convertTemp();

    return 0;
}
