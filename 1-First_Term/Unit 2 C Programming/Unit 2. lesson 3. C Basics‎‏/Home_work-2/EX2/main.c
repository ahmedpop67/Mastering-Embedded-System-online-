#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
char a;
printf("Enter an alphabet: ");
scanf("%c",&a);
(a=='a'||a=='e'||a=='o'||a=='i'||a=='u')?printf("%c is vowel.",a):printf("%c is condonant .",a);
}