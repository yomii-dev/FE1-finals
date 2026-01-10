#include <iostream>
using namespace std;

class OhmsLaw {
public:
    int getVoltage(int i, int r) {
        return i * r;
    }

    int getCurrent(int v, int r) {
        return v / r;
    }

    int getResistance(int v, int i) {
        return v / i;
    }
};

int main() {
    int v = 0; // Voltage
    int i = 0; // Current
    int r = 0; // Resistance
    int choice;

    OhmsLaw calc;

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
        cin >> i;
        cout << "Enter the value of Resistance: ";
        cin >> r;
        cout << i << " * " << r << " = " << calc.getVoltage(i, r) << "V";
        break;

    case 2:
        cout << "Enter the value of Voltage: ";
        cin >> v;
        cout << "Enter the value of Resistance: ";
        cin >> r;
        cout << v << " / " << r << " = " << calc.getCurrent(v, r) << "A";

        break;

    case 3:
        cout << "Enter the value of Voltage: ";
        cin >> v;
        cout << "Enter the value of Current: ";
        cin >> i;
        cout << v << " / " << i << " = " << calc.getResistance(v, i) << "Ω";
        
        break;

    default:
        cout << "Invalid Operation";
    }

    return 0;
}