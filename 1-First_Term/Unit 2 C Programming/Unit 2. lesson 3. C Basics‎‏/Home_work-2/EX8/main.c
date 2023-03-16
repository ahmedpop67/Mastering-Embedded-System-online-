#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
char a;
float b,c,m;
unsigned int fac=1;
do{
printf("Enter operator either + or - or * or divide : ");
scanf("%c",&a);
}while(a!='+'&&a!='-'&&a!='*'&&a!='/');
printf("Enter two number : ");
scanf("%f %f",&b,&c);
switch(a){
case '+':m=b+c; break;
case '-':m=b-c; break;
case '*':m=b*c; break;
case '/':m=b/c; break;
default :break;
}
printf("\n%.1f %c %.1f = %.1f",b,a,c,m);
}
