#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct student{
char name[100];
int roll_number;
float marks;
}student;
int main()
{
student st1[10];
int n=0;
while(n<10){
printf("\nEnter information of student %d: \n",n+1);
printf("Enter name: ");
scanf("%s",st1[n].name);
printf("Enter roll number: ");
scanf("%d",&st1[n].roll_number);
printf("Enter marks: ");
scanf("%f",&st1[n].marks);
n++;
}
n=0;
printf("\n\nDisplay information \n\n)"
while(n<10){
printf("information of rool number%d\nname: %s\nRoll: %d\nMarks: %.3f\n\n",n+1,st1[n].name,st1[n].roll_number,st1[n].marks);
n++;
}
}
