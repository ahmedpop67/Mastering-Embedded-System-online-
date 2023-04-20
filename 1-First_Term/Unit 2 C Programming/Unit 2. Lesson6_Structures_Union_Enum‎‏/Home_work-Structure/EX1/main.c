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
student st1;
printf("Enter information of student: \n");
printf("Enter name: ");
gets(st1.name);
printf("Enter roll number: ");
scanf("%d",&st1.roll_number);
printf("Enter marks: ");
scanf("%f",&st1.marks);
printf("\n\nDisplay information \nname: %s\nRoll: %d\nMarks: %.3f\n\n",st1.name,st1.roll_number,st1.marks);
}