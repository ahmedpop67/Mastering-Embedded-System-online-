#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int n,s,flag=0;
    int a[100];
    printf("Enter number of element :");
    scanf("%d",&n);
    for(int i =0; i<n;i++)
    {
        scanf ("%d",&a[i]);
    }
   printf("Enter number to be searched : ");
   scanf("%d",&s);
   for(int i =0; i<n;i++)
    {
        if (a[i]==s){
            printf("nember found at the location = %d",i+1);
            flag=1;
            break;
        }
        else flag=0;
    }
    if(flag ==0)
        printf("not found");
}