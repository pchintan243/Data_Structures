#include <stdio.h>
int main()
{
    int a[] = {0, 1, 2, 1, 0, 2, 1};
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    // printf("%d\n", length);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        if (a[i] == 0)
        {
            c1++;
        }
        else if (a[i] == 1)
        {
            c2++;
        }
        else if (a[i] == 2)
        {
            c3++;
        }
    }
    printf("\n");
    // int arr[7];
    for (int i = 0; i < 7; i++)
    {
        if (c1 != 0)
        {
            a[i] = 0;
            c1--;
        }
        else if (c2 != 0)
        {
            a[i] = 1;
            c2--;
        }
        else if (c3 != 0)
        {
            a[i] = 2;
            c3--;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}