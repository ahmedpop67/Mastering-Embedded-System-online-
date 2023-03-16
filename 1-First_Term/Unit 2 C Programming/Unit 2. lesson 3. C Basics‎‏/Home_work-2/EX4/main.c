#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
float a;
printf("Enter a number: ");
scanf("%f",&a);
if (a<0)
printf("%.2f is negetive.",a);
else if(a>0)
printf("%.2f is positive.",a);
else
printf("You entered zero.");
}