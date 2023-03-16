#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
int a;
printf("Enter an integer you want to check: ");
scanf("%d",&a);
a%2?printf("%d is odd.",a):printf("%d is even.",a);
}
