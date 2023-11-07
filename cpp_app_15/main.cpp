#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    if (num <= 3)
    {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrimes(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]))
        {
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const int arraySize = 10;
    int intArr[arraySize];

    cout << "Original array:" << endl;

    for (int i = 0; i < arraySize; i++)
    {
        intArr[i] = rand() % 100;
        cout << intArr[i] << " ";
    }

    cout << endl;

    int primeCount = countPrimes(intArr, arraySize);

    cout << "Prime numbers in array: " << primeCount << endl;

    return 0;
}
