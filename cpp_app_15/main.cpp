#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void findMinMax(int arr[], int size, int& min_value, int& max_value, int& min_index, int& max_index) 
{
    min_value = arr[0];
    max_value = arr[0];
    min_index = 0;
    max_index = 0;

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < min_value) 
        {
            min_value = arr[i];
            min_index = i;
        }
        else if (arr[i] > max_value)
        {
            max_value = arr[i];
            max_index = i;
        }
    }
}

int main()
{
    const int arraySize = 6;  
    int arr[arraySize];

    srand(time(nullptr));

    for (int i = 0; i < arraySize; i++) 
    {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Original array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int min_value, max_value, min_index, max_index;

    findMinMax(arr, arraySize, min_value, max_value, min_index, max_index);

    cout << "Minimum value: " << min_value << endl;
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
