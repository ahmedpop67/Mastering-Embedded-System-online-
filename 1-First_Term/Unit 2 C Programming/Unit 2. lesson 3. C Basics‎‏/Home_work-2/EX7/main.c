#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
int a;
unsigned int fac=1;
printf("Enter an integer: ");
scanf("%d",&a);
if(a<0)
printf("Error!!! Factorial of negative number doesn't exist.");
else
while(a>=1){
    fac*=a;
    a--;
}
printf("Factorial = %d",fac);
}
