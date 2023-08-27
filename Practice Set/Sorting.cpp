#include <iostream>
using namespace std;

void d(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void s(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int c(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

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
            s(a[i], a[j]);
        }
    } while (i<j);
    s(a[low], a[j]);

    return j;
}
void b(int *a, int low, int high)
{
    int part;
    if (low < high)
    {
        part = c(a, low, high);
        b(a, low, part - 1);
        b(a, part + 1, high);
    }
}

int main()
{
    int a[] = {45, 34, 32, 12, 78};
    int n = 5;

    b(a, 0, n - 1);
    d(a, n);
    return 0;
}