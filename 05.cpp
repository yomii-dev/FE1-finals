#include <iostream>
#include <cmath>
using namespace std;

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
            cout << "Time of Flight: "
                 << (2 * v * sin(angleRad)) / g << " s\n";
        } 
        else if (choice == 2) {
            cout << "Maximum Height: "
                 << pow(v * sin(angleRad), 2) / (2 * g) << " m\n";
        } 
        else if (choice == 3) {
            cout << "Range: "
                 << (pow(v, 2) * sin(2 * angleRad)) / g << " m\n";
        }
    }
};

void runProjectileMotion() {
    ProjectileMotion app;
    app.run();
}

int main() {
    // Projectile Motion Calculations - tofu (i dont know if i did this int / void thing right)
    runProjectileMotion();

    return 0;
}