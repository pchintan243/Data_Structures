#include <iostream>
using namespace std;
// count sort is one of the fastest way to sorting an array

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMaximum(int *a, int n)
{
    int max = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int *a, int n)
{
    int i, j;
    int max = findMaximum(a, n);

    // Create the array which size of maximum_element + 1
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Intialize all element to 0
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Increment the value by 1 if value is there in the array
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for given array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int length;
    cout << "Enter the size of array:" << endl;
    cin >> length;
    int arr[length];
    cout << "Enter the elements of an array:" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    countSort(arr, length);

    cout << "After sorting: " << endl;
    displayArray(arr, length);
    return 0;
}