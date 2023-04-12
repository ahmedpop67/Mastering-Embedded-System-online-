#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
	float a[2][2],b[2][2],c[2][2];
	printf("Enter elements of 1st matrix\n");
	for(int i=0;i<2;i++){
		for (int j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	printf("\nEnter elements of 2st matrix\n");
	for(int i=0;i<2;i++){
		for (int j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			scanf("%f",&b[i][j]);
		}
	}
	printf("Sum of matrix:");
    for(int i=0;i<2;i++){
		for (int j=0;j<2;j++)
		{
			printf("%.1f ",a[i][j]+b[i][j]);
		}
		printf("\n");
	}

}
