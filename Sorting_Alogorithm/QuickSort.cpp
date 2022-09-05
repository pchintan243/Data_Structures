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

int parition(int *arr, int low, int high)
{
    int temp;
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = parition(arr, low, high);
        // displayArray(arr, high + 1);                     // display the array after each partition
        quickSort(arr, low, partitionIndex - 1);  // Sort left sub array
        quickSort(arr, partitionIndex + 1, high); // Sort right sub array
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

    quickSort(arr, 0, length - 1);

    cout << "After sorting: " << endl;
    displayArray(arr, length);

    return 0;
}