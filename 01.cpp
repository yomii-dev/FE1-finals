#include <iostream>
#include <string>
#include <limits>
using namespace std;

   int main() {
   int inputChoice;
   double input, result;
   string unit;

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

   //Not gonna lie, I asked ChatGPT for help with this part
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
   //Until here:skyrim_skeleton:

   switch (inputChoice) {
      case 1:  result = input / 1000; unit = " km"; break;
      case 2:  result = input / 1609.34; unit = " mi"; break;
      case 3:  result = input * 0.621371; unit = " mi"; break;
      case 4:  result = input * 1000; unit = " m"; break;
      case 5:  result = input * 1.60934; unit = " km"; break;
      case 6:  result = input * 1609.34; unit = " m"; break;
      case 7:  result = input / 60; unit = " min"; break;
      case 8:  result = input / 3600; unit = " h"; break;
      case 9:  result = input / 86400; unit = " days"; break;
      case 10: result = input * 60; unit = " s"; break;
      case 11: result = input * 3600; unit = " s"; break;
      case 12: result = input * 86400; unit = " s"; break;
      case 13: result = input * 3.6; unit = " km/h"; break;
      case 14: result = input * 12960; unit = " km/h^2"; break;
   }

   cout << "Result: " << result << unit << endl;
   break;
   }

return 0;
}
