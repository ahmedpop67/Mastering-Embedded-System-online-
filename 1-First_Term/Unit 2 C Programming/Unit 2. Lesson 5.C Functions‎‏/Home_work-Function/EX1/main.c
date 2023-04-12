#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int prime(int n,int m)
{
    int flag =0;
for(int i=n+1;i<m;i++){
    flag=0;
    for(int j=2;j<i;j++){
       if (i%j==0){flag=1;break;}
    }
     if (flag==0)printf("%d ",i);
}
}
int main()
{
int n,m;
printf("Enter two number(intserval): ");
scanf("%d%d",&n,&m);
prime(n,m);
}
