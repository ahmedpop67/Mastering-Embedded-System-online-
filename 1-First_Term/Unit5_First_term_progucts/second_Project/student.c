/*
 * student.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */
#include "student.h"
#include <string.h>
FIFO_BUF_t fifo_buf;

stinfo student_data[50];
int state=0;
char fname[50];
char lname[50];
float gpa;
int roll;
int cid[5];


int instr(void)
{
    printf("\n   *************************************\n");
    printf("   *         * student Data Base *        *\n");
    printf("   *************************************\n");
    printf("%s", "\nEnter your choice\n"
           "     1 - Add student details manually\n"
           "     2 - Add student details from file\n"
           "     3 - find student details by roll number\n"
           "     4 - find student details by first name\n"
           "     5 - find student details by course id\n"
           "     6 - find total number of students\n"
           "     7 - Delete the student details by Roll number\n"
           "     8 - Updata the student details by Roll number\n"
           "     9 - Show all information\n"
		   "     10- EXIT\n");
    unsigned int menuChoice;
    printf("%s", "? ");
    scanf("%u", &menuChoice);
    return menuChoice;
}

void full_the_record()
{
    if (state==0){
	fflush(stdin);
	fflush(stdout);
	printf("enter your first name: ");
	gets(student_data[fifo_buf.count].fname);
	fflush(stdin);
	fflush(stdout);
	printf("enter your last name: ");
	gets(student_data[fifo_buf.count].lname);
	fflush(stdin);
	fflush(stdout);
	int roll;
	printf("enter your roll number: ");
	scanf("%d",&roll);
	while(id_is_exist(roll)){
        printf("  * this roll number is used or wrong Please enter another ID: ");
         scanf("%d",&roll);
         fflush(stdin);
	}
	student_data[fifo_buf.count].roll=roll;
    printf("enter your gpa: ");
    scanf("%f",&student_data[fifo_buf.count].GPA);
    fflush(stdin);
	fflush(stdout);
	for (int i=0;i<5;i++){
	printf("enter %dst coure id: ",i+1);
	scanf("%d",&student_data[fifo_buf.count].cid[i]);
	}
    }
   else
    {
        strcpy(student_data[fifo_buf.count].fname,fname);
        strcpy(student_data[fifo_buf.count].lname,lname);
        student_data[fifo_buf.count].roll=roll;
        student_data[fifo_buf.count].GPA=gpa;
        for (int i=0;i<5;i++)
     {
         student_data[fifo_buf.count].cid[i]=cid[i];
     }
    }
}
void Add_student()
{
    if (fifo_buf.count>fifo_buf.length)
        {
            printf("list is full try letter\n");
            return 0;
        }
   full_the_record();
   if(fifo_buf.head=fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        fifo_buf.head=fifo_buf.base;
   else
        fifo_buf.head++;
   fifo_buf.count++;
}
int delete_student()
{
    int id;
    fflush(stdin);
	fflush(stdout);
	printf("enter roll number that you want to delete from list: ");
	scanf("%d",&id);
	stinfo *temp=fifo_buf.tail;
int i=0;
while(i<fifo_buf.count && temp->roll!=id)
{
    if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        temp=fifo_buf.base;
    else
        temp++;
    i++;
}
if(i>=fifo_buf.count)
    printf("not found this roll number");
else{
    char temp_fname[50];
    strcpy(temp_fname,temp->fname);
    char temp_lname[50];
    strcpy(temp_lname,temp->lname);
    int temp_roll=temp->roll;
    int temp_cid[5];
    float temp_gpa=temp->GPA;
    for (int i=0;i<5;i++)
    {
      temp_cid[i]=temp->cid[i];
    }
    strcpy(temp->fname,fifo_buf.tail->fname);
    strcpy(fifo_buf.tail->fname,temp_fname);
    strcpy(temp->lname,fifo_buf.tail->lname);
    strcpy(fifo_buf.tail->lname,temp_lname);
    temp->roll=fifo_buf.tail->roll;
    fifo_buf.tail->roll=temp_roll;
    temp->GPA=fifo_buf.tail->GPA;
    fifo_buf.tail->GPA=temp_gpa;
    for (int i=0;i<5;i++)
    {
        temp->cid[i]=fifo_buf.tail->cid[i];
        fifo_buf.tail->cid[i]=temp_cid[i];
    }
       if(fifo_buf.tail==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
         fifo_buf.tail=fifo_buf.base;
   else
        fifo_buf.tail++;
   fifo_buf.count--;
   printf("\n\t student of roll number %d is deleted \n\n",id);
}
   printf("\n");
system("pause");

}
int id_is_exist(int id)
{
stinfo *temp=&student_data[0];
int i=0;
while(i<=fifo_buf.length && temp->roll!=id)
{
    temp=&student_data[++i];
}
if(i>fifo_buf.length)
    return 0;
else return 1;
}
void displsy_student()
{
    if(fifo_buf.count==0)
     printf("the list is empty\n\n");
    else{
    stinfo *temp=fifo_buf.tail;
    int i=0;
    printf("\n\n\t\t\t\t\t                            * the list is *\n");
        printf("\t\t\t\t\t                      ************************* \n");
        printf(" fname\t\tlname\t\troll_Num\t\tGPA\t1st c_id\t2st c_id\t3st c_id\t4st c_id\t5st c_id\n****************************************************************************************************************************************\n");
    while(i<fifo_buf.count)
    {
        printf("\n%s\t\t%s\t\t%d\t\t\t%.2f\t %d\t\t%d   \t\t%d\t\t%d \t\t%d   \t\n\n",temp->fname,temp->lname,temp->roll,temp->GPA,temp->cid[0],temp->cid[1],temp->cid[2],temp->cid[3],temp->cid[4]);
        if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
           temp=fifo_buf.base;
        else
           temp++;
        i++;
    }
   printf("\n****************************************************************************************************************************************\n");
    }
}
void search_student_by_rollnum()
{
    int id;
    fflush(stdin);
	fflush(stdout);
	printf("enter your roll number: ");
	scanf("%d",&id);
	stinfo *temp=fifo_buf.tail;
int i=0;
while(i<fifo_buf.count && temp->roll!=id)
{
    if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        temp=fifo_buf.base;
    else
        temp++;
    i++;
}
if(i>=fifo_buf.count)
    printf("not found this roll number");
else
{
    printf("\t\tthis roll number is found\n\n");
    printf("\t\tfirst name is: %s\n\t\tlast name is: %s\n\t\troll number is: %d\n\t\tgpa is: %.2f",temp->fname,temp->lname,temp->roll,temp->GPA);
   for (int i=0;i<5;i++){
	printf("\n\t\t%dst coure id is: %d",i+1,temp->cid[i]);
   }
}
   printf("\n");
system("pause");

}
void search_student_by_fname()
{
    int flag=0;
    char fname[50];
    fflush(stdin);
	fflush(stdout);
	printf("enter first name: ");
	gets(fname);
	stinfo *temp=fifo_buf.tail;
int i=0;
while(i<=fifo_buf.count)
{
    if(!strcmp(temp->fname,fname))
    {
        //printf("\t\tthis roll number is found\n\n");
        printf("\t\tfirst name is: %s\n\t\tlast name is: %s\n\t\troll number is: %d\n\t\tgpa is: %.2f",temp->fname,temp->lname,temp->roll,temp->GPA);
        for (int i=0;i<5;i++){
	    printf("\n\t\t%dst coure id is: %d",i+1,temp->cid[i]);
   }
         flag =1;
    }
    printf("\n\n");
    if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        temp=fifo_buf.base;
    else
        temp++;
    i++;
}
if(flag ==0 )
    printf("not found this first name\n\n");
printf("\n");
system("pause");
}
void search_student_by_cid()
{
    int cid;
    int flag=0;
    fflush(stdin);
	fflush(stdout);
	printf("enter your course id: ");
	scanf("%d",&cid);
	stinfo *temp=fifo_buf.tail;
int i=0;
while(i<=fifo_buf.count)
{
    if(temp->cid[0]==cid || temp->cid[1]==cid ||temp->cid[2]==cid || temp->cid[3]==cid || temp->cid[4]==cid)
    {
        //printf("\t\tthis roll number is found\n\n");
        printf("\t\tfirst name is: %s\n\t\tlast name is: %s\n\t\troll number is: %d\n\t\tgpa is: %.2f",temp->fname,temp->lname,temp->roll,temp->GPA);
        for (int i=0;i<5;i++){
	    printf("\n\t\t%dst coure id is: %d",i+1,temp->cid[i]);
   }
        flag =1;
    }
    printf("\n\n");
    if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        temp=fifo_buf.base;
    else
        temp++;
    i++;
}
if(flag==0)
    printf("not found this course id\n\n");
   printf("\n");
system("pause");
}
void updata_student()
{
    int id;
    fflush(stdin);
	fflush(stdout);
	printf("enter roll number: ");
	scanf("%d",&id);
	stinfo *temp=fifo_buf.tail;
int i=0;
while(i<=fifo_buf.count && temp->roll!=id)
{
    if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
        temp=fifo_buf.base;
    else
        temp++;
    i++;
}
if(i>=fifo_buf.count)
    printf("not found this roll number");
else
{
    printf("\t\tthis roll number is found\n\n");
    printf("\t\tfirst name is: %s\n\t\tlast name is: %s\n\t\troll number is: %d\n\t\tgpa is: %.2f",temp->fname,temp->lname,temp->roll,temp->GPA);
   for (int i=0;i<5;i++){
	printf("\n\t\t%dst coure id is: %d",i+1,temp->cid[i]);
   }
   int choise;
   do{
   printf("\n\nselect what you want to updata\n\t\t1-first name\n\t\t2-last name\n\t\t3-roll number\n\t\t4-GPA\n\t\t5-cid\n");
   scanf("%d",&choise);
   }while(choise>5 || choise<1);
switch(choise)
{
case 1:
    fflush(stdin);
	fflush(stdout);
    printf("enter new first name");
    gets(temp->fname);
    break;
case 2:
    fflush(stdin);
	fflush(stdout);
    printf("enter new last name");
    gets(temp->fname);
    break;
case 3:
	printf("enter new roll number: ");
	int roll;
	scanf("%d",&roll);
	while(id_is_exist(roll)){
        printf("  * this roll number is used or wrong Please enter another ID: ");
         scanf("%d",&roll);
         fflush(stdin);
	}
	temp->roll=roll;
    break;
case 4:
    fflush(stdin);
	fflush(stdout);
    printf("enter new gpa: ");
    scanf("%f",&temp->GPA);
    break;
case 5:
    fflush(stdin);
	fflush(stdout);
	for (int i=0;i<5;i++){
	printf("enter %dst coure id: ",i+1);
	scanf("%d",&temp->cid[i]);
	}
    break;
}
}
   printf("\n");
system("pause");

}
int get_length()
{
return fifo_buf.count;
}
void Add_student_fromfile()
{
	FILE *f;
	int i=1;
	state=1;
	char*ptr;
	char line[1024];
	if((f=fopen("pop.csv","r"))==NULL){
        printf("file not found\n\n");
	    return 0;
	}
    while(fgets(line, sizeof line, f) !=NULL){
     if ((strlen(line)>0) && (line[strlen (line) - 1] == '\n'))
        line[strlen (line) - 1] = '\0';
     ptr=strtok(line,",");
     strcpy(fname, ptr);
     ptr=strtok(NULL,",");
     strcpy(lname, ptr);
     ptr=strtok(NULL,",");
     roll=atoi(ptr);
     ptr=strtok(NULL,",");
     gpa=atof(ptr);
     for (int i=0;i<5;i++)
     {
        ptr=strtok(NULL,",");
        cid[i]=atoi(ptr);
     }
     if(i==1) i=0;
     else
	 Add_student();
    }
	printf("\n     * all students from file are inserted *   \n\n\n");
	fclose(f);
}
void write_into_file()
{
    stinfo *temp=fifo_buf.tail;
    int i=0;
FILE *f=fopen("pop.csv","w+");
    if(f==NULL)
       printf("file not found");
    else{
	  fprintf(f,"fname,lname,roll number,GPA,1st c_id,2st c_id,3st c_id,4st c_id,5st c_id\n");
	  while(i<fifo_buf.count){
         fprintf(f,"%s,%s,%d,%.2f,%d,%d,%d,%d,%d\n",temp->fname,temp->lname,temp->roll,temp->GPA,temp->cid[0],temp->cid[1],temp->cid[2],temp->cid[3],temp->cid[4]);
         if(temp==fifo_buf.base+fifo_buf.length*(sizeof(stinfo)))
            temp=fifo_buf.base;
       else
            temp++;
       i++;
	    }
	  }
	  fclose(f);
}
FIFO_status FIFO_IS_FULL(FIFO_BUF_t*fifo_buf)
{
	if(fifo_buf->count==fifo_buf->length)
		return FIFO_full;
	return FIFO_no_error;
}
FIFO_status FIFO_init()
{
		fifo_buf.base=&student_data;
		fifo_buf.head=&student_data;
		fifo_buf.tail=&student_data;
		fifo_buf.length=50;
		fifo_buf.count=0;
		return FIFO_no_error;
}
