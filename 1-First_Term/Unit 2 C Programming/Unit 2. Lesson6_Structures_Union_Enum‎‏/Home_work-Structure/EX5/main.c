#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define area(r) 3.14*r*r
int main()
{
  int r;
printf("Enter the radies : ");
scanf("%d",&r);
printf("\nArea = %.2f\n",area(r));
}
