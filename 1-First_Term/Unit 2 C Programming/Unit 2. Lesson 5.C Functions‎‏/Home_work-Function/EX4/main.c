#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int powe(int n,int m)
{
    if(m==0) return 1;
return n*powe(n,m-1);
}
int main()
{
int n,m;
printf("Enter base number : ");
scanf("%d",&n);
printf("Enter power number : ");
scanf("%d",&m);
printf("%d^%d = %d",n,m,powe(n,m));
}