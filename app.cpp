#include <iostream>
using namespace std;

class Menu {
  private:
    /* Class Initializations dito */
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
            cout << "10. Freefall\n\n";

            cout << "Choose the number of the calculator to begin(q to quit): ";
            cin >> choice;

            switch (choice) {
            case 1:
                // Call ung calc nung choice

                break;
            case 2:
                // Call ung calc nung choice

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
            default:
                cout << "Invalid Input.\n\n";
                break;
            }
        }
    }
};

int main() {
    cout << "lmao";

    Menu app;
    app.showMenu();

    return 0;
}
