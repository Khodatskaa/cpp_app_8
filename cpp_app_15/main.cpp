#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void reverseArray(T arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main()
{
    const int arraySize = 5;  
    int intArr[arraySize];

    srand(time(nullptr));

    for (int i = 0; i < arraySize; i++)
    {
        intArr[i] = rand() % 100 + 1;
    }

    cout << "Original array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    reverseArray(intArr, arraySize);

    cout << "Reversed array:" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    return 0;
}
