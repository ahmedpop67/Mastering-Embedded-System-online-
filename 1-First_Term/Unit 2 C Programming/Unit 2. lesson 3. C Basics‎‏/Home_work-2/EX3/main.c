#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
float a,b,c;
printf("Enter three num: ");
scanf("%f",&a);
scanf("%f",&b);
scanf("%f",&c);
float maxn;
if (a>b && a>c)
    maxn=a;
else if (b>a && b>c)
    maxn=b;
else
    maxn=c;
printf("%.2f",maxn);
}