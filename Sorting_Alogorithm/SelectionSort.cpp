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

void selectionSort(int *arr, int n)
{
    int indexOfMin;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        if (indexOfMin != i)
        {
            int temp = arr[i];
            arr[i] = arr[indexOfMin];
            arr[indexOfMin] = temp;
        }
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

    selectionSort(arr, length);

    cout << "After sorting: " << endl;
    displayArray(arr, length);

    return 0;
}