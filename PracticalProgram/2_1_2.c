#include <stdio.h>
int main()
{

    int i, n, arr[100], num, pos = 0;

    printf("Enter the size of array : ");
    scanf("%d", &n);

    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be entered : ");
    scanf("%d", &num);

    /*Find position where elements should be entered.*/

    for (i = 0; i < n; i++)
    {
        if (arr[i] < num)
        {
            pos++;
        }
        else
        {
            break;
        }
    }

    printf("%d should be entered at position %d", num, pos);

    /* Execute a loop to move all elements right by 1 position having
    index greater than position where to insert element */

    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert element at given position
    arr[pos] = num;

    // Finally print new array after insertion of new element
    printf("\nThe new array is : ");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}