#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, a[1000], i;
    scanf("%d", &num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=num-1;i>=0;i--)
    {
        printf("%d\t",a[i]);
    }
}
