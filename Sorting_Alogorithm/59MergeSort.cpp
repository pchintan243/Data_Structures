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

void mergeSort(int *a, int low, int mid, int high)
{
    int b[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void partitioning(int *a, int low, int high)
{
    //                               4 6 2 3 5 7
    //                      4 6 2                  3 5 7
    //                 4         6 2             3       5 7
    //           4           6          2      3      5       7

    int mid;
    if (low < high)
    {
        // 4 6 2 5 3 7
        mid = (low + high) / 2;
        partitioning(a, low, mid);
        // low0 mid2 high5
        // low0 mid1 high2
        // low0 mid0 high1
        partitioning(a, mid + 1, high);
        // low3 mid4 high5
        // low3 mid3 high4
        mergeSort(a, low, mid, high);
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

    partitioning(arr, 0, length - 1);

    cout << "After sorting: " << endl;
    displayArray(arr, length);
    return 0;
}