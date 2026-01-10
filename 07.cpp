#include <iostream>
using namespace std;

class Temperature {
  public:
    void convertTemp() {
        double tempNum = _takeTemp();

        // May Change
        char tempUnit = _chooseUnit(0);
        char convertTempTo = _chooseUnit(1);

        // TODO:
        double answer = fahrenheitToCelsius(tempNum);

        cout << tempNum << tempUnit << " -> " << answer << convertTempTo;
    }

    double _takeTemp() {
        double temp;
        cout << "1. What temperature do you want to convert? ";
        cin >> temp;

        return temp;
    }

    char _chooseUnit(int questionIndex) {
        char unit;

        string prompts[3] = {
            "2. Pick the unit that your temperature IS IN (F/C/K): ",
            "3. Pick the unit that you want to convert TO (F/C/K): "};

        while (true) {
            cout << prompts[questionIndex];
            cin >> unit;

            if (!_isValidUnit(unit)) {
                cout << "Please input a valid unit (F/C/K).\n";
                continue;
            }

            return unit;
        }
    }

    bool _isValidUnit(char input) {
        char validUnits[3] = {'F', 'C', 'K'};

        for (int i = 0; i < 3; i++) {
            if (input == validUnits[i]) {
                return true;
            }
        }

        return false;
    }

    /* Conversions */
    double fahrenheitToCelsius(double temp) { return ((temp - 32) / 1.8); }
};

int main() {
    // Temperature Conversion - Glen THE 2nd
    Temperature lol;
    lol.convertTemp();

    return 0;
}
