#include <iostream>
#include <cmath>
using namespace std;

// Calculate distance between two points
inline double distanceBetween(double x1, double y1,
                              double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}

// Convert degrees to radians
inline double toRadians(double degrees)
{
    return degrees * (3.141592653589793 / 180.0);
}

// Restrict value between minVal and maxVal
inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
    {
        return minVal;
    }

    if (value > maxVal)
    {
        return maxVal;
    }

    return value;
}

// Check whether point is inside safe zone
inline bool isInSafeZone(double x, double y,
                         double cx, double cy,
                         double radius)
{
    double dx = x - cx;
    double dy = y - cy;

    double distance = sqrt(dx * dx + dy * dy);

    return distance <= radius;
}

int main()
{
    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe zone radius
    double radius = 50.0;

    int n;

    cout << "Enter number of waypoints: ";
    cin >> n;

    // Dynamic arrays for waypoint coordinates
    double* x = new double[n];
    double* y = new double[n];

    // Input waypoints
    cout << "Enter waypoint coordinates:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Waypoint " << i + 1 << " X: ";
        cin >> *(x + i);

        cout << "Waypoint " << i + 1 << " Y: ";
        cin >> *(y + i);
    }

    cout << "\n--- Drone Navigation ---\n";

    // Test every waypoint
    for (int i = 0; i < n; i++)
    {
        double distance = distanceBetween(
            homeX,
            homeY,
            *(x + i),
            *(y + i)
        );

        bool safe = isInSafeZone(
            *(x + i),
            *(y + i),
            homeX,
            homeY,
            radius
        );

        cout << "\nWaypoint " << i + 1 << endl;
        cout << "Position: (" << *(x + i)
             << ", " << *(y + i) << ")" << endl;

        cout << "Distance from home: "
             << distance << endl;

        if (safe)
        {
            cout << "Inside safe zone: Yes" << endl;
        }
        else
        {
            cout << "Inside safe zone: No" << endl;
        }
    }

    // Example of toRadians()
    double degrees;

    cout << "\nEnter degrees to convert to radians: ";
    cin >> degrees;

    cout << "Radians: "
         << toRadians(degrees) << endl;

    // Example of clamp()
    double value;
    double minVal;
    double maxVal;

    cout << "\nEnter value: ";
    cin >> value;

    cout << "Enter minimum value: ";
    cin >> minVal;

    cout << "Enter maximum value: ";
    cin >> maxVal;

    cout << "Clamped value: "
         << clamp(value, minVal, maxVal) << endl;

    // Free dynamic memory
    delete[] x;
    delete[] y;

    return 0;
}