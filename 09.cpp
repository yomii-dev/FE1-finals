#include <iostream>
#include <string>

using namespace std;

class MotionCalculator {
private:
    // Conversion factors to base units (meters for distance, seconds for time)
    double toMeters(double value, const string& unit) {
        if (unit == "km") return value * 1000;
        if (unit == "miles") return value * 1609.34;
        if (unit == "m") return value;
        return value;  // Default to meters if no value was stated
    }

    double toSeconds(double value, const string& unit) {
        if (unit == "min") return value * 60;
        if (unit == "h") return value * 3600;
        if (unit == "s") return value;
        return value;  // Default to meters if no value was stated
    }

    // Convert back from base units for display
    double fromMeters(double value, const string& unit) {
        if (unit == "km") return value / 1000;
        if (unit == "miles") return value / 1609.34;
        if (unit == "m") return value;
        return value;
    }

    double fromSeconds(double value, const string& unit) {
        if (unit == "min") return value / 60;
        if (unit == "h") return value / 3600;
        if (unit == "s") return value;
        return value;
    }

public:
    // calculating distance in base units, then convert back
    double calculateDistance(double speed, double time, const string& distUnit, const string& speedUnit, const string& timeUnit) {
        double speedBase = toMeters(speed, speedUnit.substr(0, speedUnit.find('/'))) / toSeconds(1, speedUnit.substr(speedUnit.find('/') + 1));
        double timeBase = toSeconds(time, timeUnit);
        double distanceBase = speedBase * timeBase;
        return fromMeters(distanceBase, distUnit);
    }

    // calculating speed in base units, then convert back
    double calculateSpeed(double distance, double time, const string& distUnit, const string& timeUnit) {
        double distBase = toMeters(distance, distUnit);
        double timeBase = toSeconds(time, timeUnit);
        double speedBase = distBase / timeBase;  // m/s
        // return in a standard unit like m/s or km/h, return to m/s for simplicity
        return speedBase;
    }

    // calculating time in base units, then convert back
    double calculateTime(double distance, double speed, const string& distUnit, const string& speedUnit, const string& timeUnit) {
        double distBase = toMeters(distance, distUnit);
        double speedBase = toMeters(speed, speedUnit.substr(0, speedUnit.find('/'))) / toSeconds(1, speedUnit.substr(speedUnit.find('/') + 1));
        double timeBase = distBase / speedBase;
        return fromSeconds(timeBase, timeUnit);
    }
};

int main() {
    MotionCalculator calc;
    char choice;
    cout << "What do you want to calculate? (d for distance, s for speed, t for time): ";
    cin >> choice;

    if (choice == 'd' || choice == 'D') {
        double speed, time;
        string distUnit, speedUnit, timeUnit;
        cout << "Enter distance unit (m, km, miles): ";
        cin >> distUnit;
        cout << "Enter speed: ";
        cin >> speed;
        cout << "Enter speed unit (e.g., m/s, km/h, mph): ";
        cin >> speedUnit;
        cout << "Enter time: ";
        cin >> time;
        cout << "Enter time unit (s, min, h): ";
        cin >> timeUnit;
        double distance = calc.calculateDistance(speed, time, distUnit, speedUnit, timeUnit);
        cout << "Distance: " << distance << " " << distUnit << endl;
    } else if (choice == 's' || choice == 'S') {
        double distance, time;
        string distUnit, timeUnit;
        cout << "Enter distance: ";
        cin >> distance;
        cout << "Enter distance unit (m, km, miles): ";
        cin >> distUnit;
        cout << "Enter time: ";
        cin >> time;
        cout << "Enter time unit (s, min, h): ";
        cin >> timeUnit;
        double speed = calc.calculateSpeed(distance, time, distUnit, timeUnit);
        cout << "Speed: " << speed << " m/s" << endl;  // output is m/s by default
    } else if (choice == 't' || choice == 'T') {
        double distance, speed;
        string distUnit, speedUnit, timeUnit;
        cout << "Enter distance: ";
        cin >> distance;
        cout << "Enter distance unit (m, km, miles): ";
        cin >> distUnit;
        cout << "Enter speed: ";
        cin >> speed;
        cout << "Enter speed unit (e.g., m/s, km/h, mph): ";
        cin >> speedUnit;
        cout << "Enter time unit (s, min, h): ";
        cin >> timeUnit;
        double time = calc.calculateTime(distance, speed, distUnit, speedUnit, timeUnit);
        cout << "Time: " << time << " " << timeUnit << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}