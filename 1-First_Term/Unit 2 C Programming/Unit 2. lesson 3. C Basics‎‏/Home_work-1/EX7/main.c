#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
float a,b;
printf("Enter value of  a: ");
scanf("%f",&a);
printf("Enter value of  b: ");
scanf("%f",&b);
b=a+b;
a=b-a;
b=b-a;
printf("After swapping, value of a = %.2f\n",a);
printf("After swapping, value of b = %.2f",b);
}
