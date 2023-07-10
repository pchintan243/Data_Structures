#include <iostream>
using namespace std;
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void selctionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }
    }
    display(arr, n);
}

int main()
{
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "the element: ";
        cin >> arr[i];
    }
    selctionSort(arr, n);

    return 0;
}