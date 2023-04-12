#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int n,n2,l;
    int a[100];
printf("Enter no of elements : ");
scanf("%d",&n);
for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
 printf("Enter the element to be inserted : ");
scanf("%d",&n2);
printf("Enter the location : ");
scanf("%d",&l);
for(int i=n;i>=l;i--)
{
a[i]=a[i-1];
}
n++;
a[l-1]=n2;
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
