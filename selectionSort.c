#include <stdio.h>
void selectionSort(int a[], int n)
{
    int temp;
    int position;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {    
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[position] > a[j])
            {
                position = j;
            }
        }
        if (position != i)
        {
            temp = a[position];
            a[position] = a[i];
            a[i] = temp;
        }
    }
}
int main()
{
    int i, a[100], n;
    
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    printf("Enter the element:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}