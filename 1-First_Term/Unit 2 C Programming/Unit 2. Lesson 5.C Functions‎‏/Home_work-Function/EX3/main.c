#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
void rev(char *c)
{
if(*c){
    rev(c+1);
    printf("%c",*c);
}
}
int main()
{
char c[100];
printf("Enter a sentence : ");
gets(c);
rev(c);
}
