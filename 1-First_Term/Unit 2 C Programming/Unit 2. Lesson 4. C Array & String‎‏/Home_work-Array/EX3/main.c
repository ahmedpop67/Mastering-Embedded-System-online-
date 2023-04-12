#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int n,m;
    int a[100][100];
printf("Enter rows and column of matrix: ");
scanf("%d %d",&n,&m);
printf("Enter elements of matrix: \n");
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        printf("Enter elements of a%d%d: ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
}
printf("Entered matrix: \n");
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        printf("%d ",a[i][j]);
    }
    printf("\n");
}
printf("transpose of matrix: \n");
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        printf("%d ",a[j][i]);
    }
    printf("\n");
}
}