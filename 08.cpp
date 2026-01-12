#include <iostream>
using namespace std;

class PressureVolumeCalculator {
public:
    void run() {
        char repeat;

        cout << "\n=== Pressure & Volume Calculator ===\n";

        while (true) {
            int law = _pickLaw();

            if (law == 1) {
                _boylesLaw();
            } else {
                _idealGasLaw();
            }

            cout << "\nCalculate another gas problem? [y/n] ";
            cin >> repeat;

            if (repeat == 'n' || repeat == 'N') {
                return;
            }
        }
    }

private:
    const double R = 8.314;

    int _pickLaw() {
        int choice;

        while (true) {
            cout << "\nPick a law:\n";
            cout << "1. Boyle's Law\n";
            cout << "2. Ideal Gas Law\n";
            cout << "Choice: ";
            cin >> choice;

            if (cin.fail() || (choice != 1 && choice != 2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice.\n";
                continue;
            }

            return choice;
        }
    }

    void _boylesLaw() {
        int solveFor;
        double P1, V1, P2, V2;

        cout << "\n--- Boyle's Law (P1V1 = P2V2) ---\n";
        cout << "Solve for:\n";
        cout << "1. P1\n2. V1\n3. P2\n4. V2\n";
        cout << "Choice: ";
        cin >> solveFor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            return;
        }

        if (solveFor == 1) {
            cout << "Enter V1, P2, V2: ";
            cin >> V1 >> P2 >> V2;
            cout << "P1 = " << (P2 * V2) / V1 << " Pa\n";
        } 
        else if (solveFor == 2) {
            cout << "Enter P1, P2, V2: ";
            cin >> P1 >> P2 >> V2;
            cout << "V1 = " << (P2 * V2) / P1 << " m^3\n";
        } 
        else if (solveFor == 3) {
            cout << "Enter P1, V1, V2: ";
            cin >> P1 >> V1 >> V2;
            cout << "P2 = " << (P1 * V1) / V2 << " Pa\n";
        } 
        else if (solveFor == 4) {
            cout << "Enter P1, V1, P2: ";
            cin >> P1 >> V1 >> P2;
            cout << "V2 = " << (P1 * V1) / P2 << " m^3\n";
        } 
        else {
            cout << "Invalid option.\n";
        }
    }

    void _idealGasLaw() {
        int solveFor;
        double P, V, n, T;

        cout << "\n--- Ideal Gas Law (PV = nRT) ---\n";
        cout << "Solve for:\n";
        cout << "1. Pressure (P)\n";
        cout << "2. Volume (V)\n";
        cout << "3. Moles (n)\n";
        cout << "4. Temperature (T)\n";
        cout << "Choice: ";
        cin >> solveFor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            return;
        }

        if (solveFor == 1) {
            cout << "Enter V, n, T: ";
            cin >> V >> n >> T;
            cout << "P = " << (n * R * T) / V << " Pa\n";
        } 
        else if (solveFor == 2) {
            cout << "Enter P, n, T: ";
            cin >> P >> n >> T;
            cout << "V = " << (n * R * T) / P << " m^3\n";
        } 
        else if (solveFor == 3) {
            cout << "Enter P, V, T: ";
            cin >> P >> V >> T;
            cout << "n = " << (P * V) / (R * T) << "\n";
        } 
        else if (solveFor == 4) {
            cout << "Enter P, V, n: ";
            cin >> P >> V >> n;
            cout << "T = " << (P * V) / (n * R) << " K\n";
        } 
        else {
            cout << "Invalid option.\n";
        }
    }
};

void runPressureVolume() {
    PressureVolumeCalculator app;
    app.run();
}

int main() {
    // Pressure and Volume Calculations - tofu (i dont know if i did this int / void thing right)
    runPressureVolume();

    return 0;
}