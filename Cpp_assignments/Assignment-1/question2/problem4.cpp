#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax)
{
    // If size is invalid
    if (size <= 0)
    {
        return false;
    }

    // Start by assuming first element is min and max
    int* minPtr = const_cast<int*>(rawData);
    int* maxPtr = const_cast<int*>(rawData);

    // Scan the packet
    for (int i = 1; i < size; i++)
    {
        if (*(rawData + i) < *minPtr)
        {
            minPtr = const_cast<int*>(rawData + i);
        }

        if (*(rawData + i) > *maxPtr)
        {
            maxPtr = const_cast<int*>(rawData + i);
        }
    }

    // Give the addresses back to the caller
    *outMin = minPtr;
    *outMax = maxPtr;

    return true;
}

int main()
{
    int packet[] = {45, 12, 67, 8, 55, 31};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr))
    {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}