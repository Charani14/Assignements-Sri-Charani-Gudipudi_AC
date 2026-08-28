#include <iostream>
#include <cmath>
using namespace std;

// Calculate RMS
double computeRMS(double* signal, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (*(signal + i)) * (*(signal + i));
    }

    return sqrt(sum / n);
}

// Normalise the signal
void normalise(double* signal, int n)
{
    double maxValue = 0;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        double value = *(signal + i);

        if (value < 0)
        {
            value = -value;
        }

        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    // Divide every element by maximum value
    if (maxValue != 0)
    {
        for (int i = 0; i < n; i++)
        {
            *(signal + i) = *(signal + i) / maxValue;
        }
    }
}

// Count zero crossings
int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*(signal + i) < 0 && *(signal + i + 1) > 0) ||
            (*(signal + i) > 0 && *(signal + i + 1) < 0))
        {
            count++;
        }
    }

    return count;
}

// Apply gain
void applyGain(double* signal, int n, double gainFactor)
{
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) * gainFactor;
    }
}

// Print array
void printArray(double* signal, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(signal + i) << " ";
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of samples: ";
    cin >> n;

    // Dynamic array
    double* signal = new double[n];

    cout << "Enter " << n << " signal values:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> *(signal + i);
    }

    cout << "\nBefore normalise: ";
    printArray(signal, n);

    // Calculate RMS
    double rms = computeRMS(signal, n);
    cout << "RMS = " << rms << endl;

    // Count zero crossings
    int crossings = countZeroCrossings(signal, n);
    cout << "Zero crossings = " << crossings << endl;

    // Normalise
    normalise(signal, n);

    cout << "After normalise: ";
    printArray(signal, n);

    // Apply gain
    double gainFactor;

    cout << "Enter gain factor: ";
    cin >> gainFactor;

    applyGain(signal, n, gainFactor);

    cout << "After applying gain: ";
    printArray(signal, n);

    // Free dynamic memory
    delete[] signal;

    return 0;
}