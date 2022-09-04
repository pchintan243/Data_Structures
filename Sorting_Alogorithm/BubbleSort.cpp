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
void bubbleSort(int *arr, int n)
{
    int temp;
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
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

    bubbleSort(arr, length);

    cout << "After sorting: " << endl;
    displayArray(arr, length);

    return 0;
}