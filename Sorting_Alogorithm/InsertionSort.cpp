#include <iostream>
using namespace std;

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *a, int n)
{
    int key;
    int j;
    // It starts from 1 because one variable is already sorted
    for (int i = 1; i < n; i++)
    {
        // 7 8 6 5 7
        key = a[i]; // 8 6 5 7
        j = i - 1;  // 0 1 2 3
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j]; // 7 7 8 6
            j--;             // 1 0 -1
        }
        a[j + 1] = key; // 5 6 7 8 7
    }
}

int main()
{
    int length;
    cout << "Enter the size of an array:" << endl;
    cin >> length;
    int arr[length];
    cout << "Enter the element one by one:" << endl;

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, length);

    cout << "After sorting: " << endl;
    displayArray(arr, length);

    return 0;
}