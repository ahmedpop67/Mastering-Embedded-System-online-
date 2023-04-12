#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int fact(int n)
{
if(n==1)
    return 1;
return n*fact(n-1);
}
int main()
{
int n;
printf("Enter an positive integer: ");
scanf("%d",&n);
printf("%d",fact(n));
}