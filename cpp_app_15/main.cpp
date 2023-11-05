#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(int arr[][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMax(int arr[][2][3], int dim1, int dim2, int dim3) {
    int max = arr[0][0][0];
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                if (arr[i][j][k] > max) {
                    max = arr[i][j][k];
                }
            }
        }
    }
    return max;
}

int findMax(int a, int b) {
    int max_value;
    if (a > b) {
        max_value = a;
    }
    else {
        max_value = b;
    }
    return max_value;
}

int findMax(int a, int b, int c) {
    int max_value;
    if (a > b) {
        if (a > c) {
            max_value = a;
        }
        else {
            max_value = c;
        }
    }
    else {
        if (b > c) {
            max_value = b;
        }
        else {
            max_value = c;
        }
    }
    return max_value;
}

int main() {
    srand(static_cast<unsigned>(time(0));

    int arr1[5];
    int arr2[2][3];
    int arr3[2][2][3];
    int x = rand() % 100;
    int y = rand() % 100;
    int z = rand() % 100;

    cout << "1D Array: ";
    for (int i = 0; i < 5; i++) {
        arr1[i] = rand() % 100;
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "\n2D Array:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = rand() % 100;
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n3D Array:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                arr3[i][j][k] = rand() % 100;
                cout << arr3[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    int userInt1, userInt2, userInt3;

    cout << "\nEnter two integers: ";
    cin >> userInt1 >> userInt2;

    cout << "Enter three integers: ";
    cin >> userInt1 >> userInt2 >> userInt3;

    int max1D = findMax(arr1, 5);
    int max2D = findMax(arr2, 2, 3);
    int max3D = findMax(arr3, 2, 2, 3);
    int max2Int = findMax(x, y);
    int max3Int = findMax(userInt1, userInt2, userInt3);

    cout << "\nMax in 1D array: " << max1D << endl;
    cout << "Max in 2D array: " << max2D << endl;
    cout << "Max in 3D array: " << max3D << endl;
    cout << "Max of 2 integers: " << max2Int << endl;
    cout << "Max of 3 integers: " << max3Int << endl;

    return 0;
}
