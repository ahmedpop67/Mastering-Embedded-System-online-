#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
 int n;
 printf("Enter number of Data: ");
 scanf("%d",&n);
 float sum=0;
 float a[100];
 for (int i=0;i<n;i++){
 	printf("\n%d. Enter number: ",i+1);
 	scanf("%f",&a[i]);
 	sum+=a[i];
 }

 printf("\nAverage = %.2f",sum/n);
}