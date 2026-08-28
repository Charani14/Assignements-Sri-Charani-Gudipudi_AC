#include <iostream>
using namespace std;

int main() {

    double temperature[3][3];

    // Read temperatures
    cout << "Enter temperatures for 3 floors and 3 rooms:" << endl;

    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {
            cin >> temperature[floor][room];
        }
    }

    // Display table
    cout << endl;
    cout << "   ";
    cout << "     Room 1 "
         << "     Room 2 "
         << "     Room 3 " << endl;

    for (int floor = 0; floor < 3; floor++) {

        cout << "Floor " << floor + 1 << " : ";

        for (int room = 0; room < 3; room++) {
            cout << "    "<<temperature[floor][room];
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {

            if (temperature[floor][room] > hottest) {
                hottest = temperature[floor][room];
                hottestFloor = floor;
                hottestRoom = room;
            }
        }
    }

    cout << endl;
    cout << "Hottest Room : Floor " << hottestFloor + 1
         << ", Room " << hottestRoom + 1
         << " → " << hottest << "°C" << endl;

    // Find floor with highest average
    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for (int floor = 0; floor < 3; floor++) {

        double sum = 0;

        for (int room = 0; room < 3; room++) {
            sum += temperature[floor][room];
        }

        double average = sum / 3;

        if (floor == 0 || average > highestAverage) {
            highestAverage = average;
            hottestFloorNumber = floor;
        }
    }

    cout << "Hottest Floor : Floor (" << hottestFloorNumber + 1
         << highestAverage << "°C)" << endl;

    // Count rooms at WARNING or above
    int warningOrAbove = 0;

    for (int floor = 0; floor < 3; floor++) {
        for (int room = 0; room < 3; room++) {

            if (temperature[floor][room] >= 30) {
                warningOrAbove++;
            }
        }
    }

    cout << "Rooms at WARNING or above : "
         << warningOrAbove << endl;

    return 0;
}