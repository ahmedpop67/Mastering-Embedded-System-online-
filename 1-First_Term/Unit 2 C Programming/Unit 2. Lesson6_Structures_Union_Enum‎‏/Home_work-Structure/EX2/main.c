#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct Distance{
int feet;
float inch;
}Distance;
int main()
{
Distance dis1,dis2,sum;
printf("Enter information for 1st distance: \n");
printf("Enter feet: ");
scanf("%d",&dis1.feet);
printf("Enter inch: ");
scanf("%f",&dis1.inch);
printf("\nEnter information for 2st distance: \n");
printf("Enter feet: ");
scanf("%d",&dis2.feet);
printf("Enter inch: ");
scanf("%f",&dis2.inch);
sum.feet=dis1.feet+dis2.feet;
sum.inch=dis1.inch+dis2.inch;
if(sum.inch>12){
    sum.inch-=12;
    sum.feet++;
}
printf("\nsum of distance  = %d'-%.2f\n",sum.feet,sum.inch);
}
