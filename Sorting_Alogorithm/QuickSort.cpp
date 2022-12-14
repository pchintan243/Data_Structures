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

int parition(int *a, int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    // 5 4 2 7 8 1 9
    // pivot5 i3 j5  5 4 2 1 8 7 9
    // pivot5 i4 j3  1 4 2 5 8 7 9

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j; // 3
}

void quickSort(int *a, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = parition(a, low, high);
        // displayArray(a, high + 1);           // display the array after each partition
        quickSort(a, low, partitionIndex - 1);  // Sort left sub array
        quickSort(a, partitionIndex + 1, high); // Sort right sub array
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