#include <stdio.h>
int main()
{
    int i,j,m,n,a[10],index=-1;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be delete : ");
    scanf("%d",&m);

    for(i=0;i<n;i++) {

        if(a[i]==m) {

            index=i;
            break;
        }

    }
    if(index !=-1){

        for(i=index;i<n-1;i++) {
            a[i]=a[i+1];
        }
    }
    else {
        printf("element not found\n");
    }
    printf("new array\n");
    for(i=0;i<n-1;i++){

        printf("%d ",a[i]);
    }
return 0;
}