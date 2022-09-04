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

void insertionSort(int *arr, int n)
{
    int key;
    int j;
    // It starts from 1 because one variable is already sorted
    for (int i = 1; i < n; i++)
    {

        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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