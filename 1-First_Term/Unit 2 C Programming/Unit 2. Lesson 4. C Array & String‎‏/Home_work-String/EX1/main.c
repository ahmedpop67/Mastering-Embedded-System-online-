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
char c;
printf("enter a character to find frequency: ");
scanf("%c",&c);
for (int i=0;i<strlen(a);i++){
    if (a[i]==c)    n++;
}
printf ("frequency of %c = %d",c,n);
}