#include <iostream>
using namespace std;

// V1 - Call by Value
void resetSensorPairV1(int A, int B)
{
    int temp = A;
    A = B;
    B = temp;
}

// V2 - Call by Reference
void resetSensorPairV2(int& A, int& B)
{
    int temp = A;
    A = B;
    B = temp;
}

// V3 - Call by Pointer
void resetSensorPairV3(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int main()
{
    // Dynamically allocate memory
    int* A = new int;
    int* B = new int;

    // Get any values from the user
    cout << "Enter Sensor Readings: ";
    cin >> *A >> *B;

    cout << "\n--- V1: Call by Value ---" << endl;
    cout << "Before : A=" << *A << " B=" << *B << endl;

    resetSensorPairV1(*A, *B);

    cout << "After  : A=" << *A << " B=" << *B << endl;


    cout << "\n--- V2: Call by Reference ---" << endl;
    cout << "Before : A=" << *A << " B=" << *B << endl;

    resetSensorPairV2(*A, *B);

    cout << "After  : A=" << *A << " B=" << *B << endl;


    cout << "\n--- V3: Call by Pointer ---" << endl;
    cout << "Before : A=" << *A << " B=" << *B << endl;

    resetSensorPairV3(A, B);

    cout << "After  : A=" << *A << " B=" << *B << endl;


    // Free dynamically allocated memory
    delete A;
    delete B;

    return 0;
}