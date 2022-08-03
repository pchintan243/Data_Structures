#include <stdio.h>
#include <math.h>
int main()
{
    int j = 2;
    int flag = 0;
    int n;
    scanf("%d", &n);
    int count = 0;

    while (n != flag)
    {
        for (int i = 2; i <= sqrt(j); i++)
        {
            if (j % i == 0)
            {
                // printf("prime nathi%d", i);
                count = 1;
                break;
            }
            else
            {
                count = 0;
            }
        }
        if (count == 0)
        {
            printf("%d\n", j);
            flag++;
        }
        j++;
    }

    return 0;
}