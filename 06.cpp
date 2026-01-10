#include <iostream>
using namespace std;

class GravitationalForceCalculator {
private:
    const double g = 6.67e-11; // Gravitational constant

public:
    // Method to calculate gravitational force
    double calculateForce(int mass1, int mass2, int distance) {
        return (g * mass1 * mass2) / (distance * distance);
    }
};

int main() {
    GravitationalForceCalculator calculator;

    cout << "Calculate Gravitational Force\n";
    int mass1, mass2, distance;
    cout << "Enter Mass 1: ";
    cin >> mass1;
    cout << "Enter Mass 2: ";
    cin >> mass2;
    cout << "Enter Distance: ";
    cin >> distance;

    double force = calculator.calculateForce(mass1, mass2, distance);
    cout << "Gravitational Force: " << force << " N" << endl;

    return 0;
}