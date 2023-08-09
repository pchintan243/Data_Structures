#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 4, 5, 2, 10};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}