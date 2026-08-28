#include <iostream>
using namespace std;

int main() {

    int N;
    cout << "Enter number of readings: ";
    cin >> N;

    double readings[N];

    // Read N temperature values
    for (int i = 0; i < N; i++) {
        cin >> readings[i];
    }

    cout << "Readings entered : " << N << endl;

    // Print valid readings and count errors
    int skippedErrors = 0;

    cout << "Valid readings : ";

    for (int i = 0; i < N; i++) {

        // Skip sensor errors
        if (readings[i] < 0) {
            skippedErrors++;
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << endl;
    cout << "Skipped (errors) : " << skippedErrors << endl;

    // Find first reading >= 45
    bool foundCritical = false;

    for (int i = 0; i < N; i++) {

        if (readings[i] >= 45) {
            cout << "First CRITICAL : Index " << i
                 << " → " << readings[i] << "°C" << endl;
            foundCritical = true;
            break;
        }
    }

    if (!foundCritical) {
        cout << "First CRITICAL : None" << endl;
    }

    // Calculate min, max and average in one loop
    double minTemp = 0;
    double maxTemp = 0;
    double sum = 0;
    int validCount = 0;

    for (int i = 0; i < N; i++) {

        if (readings[i] < 0) {
            continue;
        }

        if (validCount == 0) {
            minTemp = readings[i];
            maxTemp = readings[i];
        }
        else {
            if (readings[i] < minTemp) {
                minTemp = readings[i];
            }

            if (readings[i] > maxTemp) {
                maxTemp = readings[i];
            }
        }

        sum += readings[i];
        validCount++;
    }

    double average = sum / validCount;


    cout << "Min : " << minTemp << "°C "
         << "Max : " << maxTemp << "°C "
         << "Avg : " << average << "°C" << endl;

    // Count categories
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < N; i++) {

        if (readings[i] < 0) {
            continue;
        }
        else if (readings[i] <= 29) {
            normal++;
        }
        else if (readings[i] <= 44) {
            warning++;
        }
        else if (readings[i] <= 59) {
            critical++;
        }
        else {
            shutdown++;
        }
    }

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}