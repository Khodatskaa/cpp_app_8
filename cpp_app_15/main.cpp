#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

void InitializeMatrix(int** Arr, int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            Arr[i][j] = rand() % 10;
        }
    }
}

void InitializeMatrix(double** Arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            Arr[i][j] = (rand() % 100) / 10;
        }
    }
}

void InitializeMatrix(char** Arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            Arr[i][j] = 'A' + rand() % 26; 
        }
    }
}

template <typename T>
void DisplayMatrix(T** Arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << Arr[i][j] << ' ';
        }
        cout << endl;
    }
}

template <typename T>
T FindMaxDiagonal(T** Arr, int n)
{
    T maxElement = Arr[0][0];
    for (int i = 1; i < n; i++)
    {
        if (Arr[i][i] > maxElement)
        {
            maxElement = Arr[i][i];
        }
    }
    return maxElement;
}

template <typename T>
T FindMinDiagonal(T** Arr, int n)
{
    T minElement = Arr[0][0];
    for (int i = 1; i < n; i++) 
    {
        if (Arr[i][i] < minElement)
        {
            minElement = Arr[i][i];
        }
    }
    return minElement;
}

template <typename T>
void SortRows(T** Arr, int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (Arr[i][j] > Arr[i][k]) 
                {
                    T temp = Arr[i][j];
                    Arr[i][j] = Arr[i][k];
                    Arr[i][k] = temp;
                }
            }
        }
    }
}

int main() 
{
    srand(static_cast<unsigned>(time(0))); 

    int n;
    cout << "n = ";
    cin >> n;

    int** intMatrix;
    double** doubleMatrix;
    char** charMatrix;

    intMatrix = new int* [n];
    doubleMatrix = new double* [n];
    charMatrix = new char* [n];

    for (int i = 0; i < n; i++) 
    {
        intMatrix[i] = new int[n];
        doubleMatrix[i] = new double[n];
        charMatrix[i] = new char[n];
    }

    InitializeMatrix(intMatrix, n);
    InitializeMatrix(doubleMatrix, n);
    InitializeMatrix(charMatrix, n);

    cout << "\nInt Matrix:" << endl;
    DisplayMatrix(intMatrix, n);
    int maxInt = FindMaxDiagonal(intMatrix, n);
    int minInt = FindMinDiagonal(intMatrix, n);
    cout << "\nMax on the main diagonal (int): " << maxInt << endl;
    cout << "Min on the main diagonal (int): " << minInt << endl;
    SortRows(intMatrix, n);
    cout << "Sorted Int Matrix:" << endl;
    DisplayMatrix(intMatrix, n);

    cout << "\nDouble Matrix:" << endl;
    DisplayMatrix(doubleMatrix, n);
    double maxDouble = FindMaxDiagonal(doubleMatrix, n);
    double minDouble = FindMinDiagonal(doubleMatrix, n);
    cout << "\nMax on the main diagonal (double): " << maxDouble << endl;
    cout << "Min on the main diagonal (double): " << minDouble << endl;
    SortRows(doubleMatrix, n);
    cout << "Sorted Double Matrix:" << endl;
    DisplayMatrix(doubleMatrix, n);

    cout << "\nChar Matrix:" << endl;
    DisplayMatrix(charMatrix, n);
    char maxChar = FindMaxDiagonal(charMatrix, n);
    char minChar = FindMinDiagonal(charMatrix, n);
    cout << "\nMax on the main diagonal (char): " << maxChar << endl;
    cout << "Min on the main diagonal (char): " << minChar << endl;
    SortRows(charMatrix, n);
    cout << "Sorted Char Matrix:" << endl;
    DisplayMatrix(charMatrix, n);

    for (int i = 0; i < n; i++) 
    {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
        delete[] charMatrix[i];
    }

    delete[] intMatrix;
    delete[] doubleMatrix;
    delete[] charMatrix;

    return 0;
}
