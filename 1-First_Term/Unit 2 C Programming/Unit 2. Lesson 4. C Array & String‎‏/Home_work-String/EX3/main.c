#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int n=0;
char a[100];
printf("enter string: ");
gets(a);
for (int i=0;i<100&&a[i]!='\0';i++){
    n++;
}
printf ("reverse the string is : ");
for (int i=n;i>=0;i--){
 printf ("%c",a[i]);
}
