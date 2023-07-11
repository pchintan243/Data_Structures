#include <iostream>
using namespace std;
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);

    return 0;
}