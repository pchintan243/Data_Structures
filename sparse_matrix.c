#include <stdio.h>
int main()
{
    // first array

    int r1, c1, sparse1[30][30], a1[30][30], b1 = 1, count1 = 0;

    // Enter row and column of first matrix

    printf("Enter the row of array: ");
    scanf("%d", &r1);
    printf("Enter the column of array: ");
    scanf("%d", &c1);

    printf("Enter the element of first array: \n");
    // Enter element of first array

    for (int i = 0; i < r1; i++)
    {

        for (int j = 0; j < c1; j++)
        {

            scanf("%d", &a1[i][j]);
        }
    }

    // non-zero element count (first matrix)

    for (int i = 0; i < r1; i++)
    {

        for (int j = 0; j < c1; j++)
        {

            if (a1[i][j] != 0)
            {

                count1++;
            }
        }
    }
    
    printf("Your first matrix is: \n");
    // print first matrix
    for (int i = 0; i < r1; i++)
    {

        for (int j = 0; j < c1; j++)
        {

            printf("%d ", a1[i][j]);
        }
        printf("\n");
    }
    // Your first matrix is sparse or not print
    if (count1 <= (r1 * c1) / 2)
    {

        printf("Sparse matrix..!!\n");
    }
    else
    {

        printf("Not sparse matrix..!!\n");
    }

    sparse1[0][0] = r1;
    sparse1[0][1] = c1;
    sparse1[0][2] = count1;

    // sparse matrix initialize (first matrix)
    for (int i = 0; i < r1; i++)
    {

        for (int j = 0; j < c1; j++)
        {

            if (a1[i][j] != 0)
            {

                sparse1[b1][0] = i;
                sparse1[b1][1] = j;
                sparse1[b1][2] = a1[i][j];
                b1++;
            }
        }
    }

    // Print the first sparse matrix..
    for (int i = 0; i <= count1; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            printf("%d ", sparse1[i][j]);
        }
        printf("\n");
    }

    printf("------------------------------------------------------------------------------------\n\n");

    // Second array

    int r2, c2, sparse2[30][30], a2[30][30], b2 = 1, count2 = 0;

    // Enter row and column of second matrix

    printf("Enter the row of array: ");
    scanf("%d", &r2);
    printf("Enter the column of array: ");
    scanf("%d", &c2);

    printf("Enter the element of second array: \n");
    // Enter element of second array

    for (int i = 0; i < r2; i++)
    {

        for (int j = 0; j < c2; j++)
        {

            scanf("%d", &a2[i][j]);
        }
    }

    // non-zero element count (second matrix)

    for (int i = 0; i < r2; i++)
    {

        for (int j = 0; j < c2; j++)
        {

            if (a2[i][j] != 0)
            {

                count2++;
            }
        }
    }
    
    printf("Your second matrix is: \n");
    // print second matrix
    for (int i = 0; i < r2; i++)
    {

        for (int j = 0; j < c2; j++)
        {

            printf("%d ", a2[i][j]);
        }
        printf("\n");
    }
    // Your second matrix is sparse or not print
    if (count2 <= (r2 * c2) / 2)
    {

        printf("Sparse matrix..!!\n");
    }
    else
    {

        printf("Not sparse matrix..!!\n");
    }

    sparse2[0][0] = r2;
    sparse2[0][1] = c2;
    sparse2[0][2] = count2;

    // second sparse matrix initialize
    for (int i = 0; i < r2; i++)
    {

        for (int j = 0; j < c2; j++)
        {

            if (a2[i][j] != 0)
            {

                sparse2[b2][0] = i;
                sparse2[b2][1] = j;
                sparse2[b2][2] = a2[i][j];
                b2++;
            }
        }
    }

    // Print the second sparse matrix..
    for (int i = 0; i <= count2; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            printf("%d ", sparse2[i][j]);
        }
        printf("\n");
    }

    printf("----------------------------------------------------------------------------\n");

    
    return 0;
}