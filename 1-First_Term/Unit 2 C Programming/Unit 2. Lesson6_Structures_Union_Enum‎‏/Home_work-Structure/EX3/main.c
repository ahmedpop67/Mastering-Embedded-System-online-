#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct comp{
float real;
float img;
}comp;
int main()
{
comp num1,num2,sum;
printf("for 1st complex number");
printf("\nenter real and imaginary respectively: ");
scanf("%f",&num1.real);
scanf("%f",&num1.img);
printf("\nfor 1st complex number");
printf("\nenter real and imaginary respectively: ");
scanf("%f",&num2.real);
scanf("%f",&num2.img);
sum.real=num1.real+num2.real;
sum.img=num1.img+num2.img;
printf("\nsum = %.2f+%.2f\n",sum.real,sum.img);
}
