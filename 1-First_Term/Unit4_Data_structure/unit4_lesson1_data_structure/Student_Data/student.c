/*
 * student.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */
#include "student.h"

int state=0;
int id;
float height;
char name[50];
pstudent head = NULL;

int instr(void)
{
    printf("\n   *************************************\n");
    printf("   *         * student Data Base *        *\n");
    printf("   *************************************\n");
    printf("%s", "\nEnter your choice\n"
           "     1 - INSERT new student manually\n"
           "     2 - INSERT new student from file\n"
           "     3 - SEARCH OF student\n"
           "     4 - DELETE OF student\n"
           "     5 - UPDATE student DETAILES\n"
           "     6 - GIT id of student\n"
           "     7 - GIT number of students\n"
           "     8 - DISPLAY ALL student DETAILES\n"
           "     9 - TO EXIT\n");
    unsigned int menuChoice;
    printf("%s", "? ");
    scanf("%u", &menuChoice);
    return menuChoice;
}
void full_the_record(pstudent new_student)
{
  if (state==0){
	int id;
	printf("\n  enter id of student: ");
    scanf("%d",&id);
    fflush(stdin);
	fflush(stdout);
	while(id_is_exist(&head,id))
		{
         printf("  * this ID is used or wrong Please enter another ID: ");
         scanf("%d",&id);
         fflush(stdin);
        }
	new_student->id=id;
	printf("\n  enter student full name: " );
	gets(new_student->name);
	fflush(stdin);
	fflush(stdout);
	printf("\n  enter height of student: ");
    scanf("%f",&(new_student->height));
    fflush(stdin);
	fflush(stdout);
  }
  else
  {
	  new_student->id=id;
	  strcpy(new_student->name, name);
	  new_student->height=height;
  }
}

int id_is_exist(pstudent *head,int id)
{

	int t=0;
    pstudent temp=*head;
    if ((*head)->id==id)
    {
        return 1;
    }
    else{
    temp=*head;
    while(temp->pnextstudent!=NULL && temp->pnextstudent->id!=id)
    {
        temp=temp->pnextstudent;
    }
    if(temp->pnextstudent==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    }
}

void Add_student()
{
	pstudent new_student=(student *)malloc(sizeof(student));
	pstudent last_student=(student *)malloc(sizeof(student));
	if(new_student!=NULL){
	if(head==NULL){
		head=new_student;
		new_student->pnextstudent=NULL;
	}
	else
	{
		last_student=head;
		while(last_student->pnextstudent)
		{
			last_student=last_student->pnextstudent;
		}
		last_student->pnextstudent=new_student;
		new_student->pnextstudent=NULL;

	}
	    system("cls");
			full_the_record(new_student);
		if(state==0)
		    printf("\n     * this student is correctly inserted *    \n\n\n");
	}
	else
		printf("No memory available.\n\n\n");
}


int delete_student()
{
    pstudent temp=head;
	pstudent last_student=NULL;
	int id;
	system("cls");
	printf("\n  enter id of student: ");
    scanf("%d",&id);
    fflush(stdin);
	fflush(stdout);
	if(temp)
	{
		while(temp)
		{
		    if(temp->id==id)
            {
                if(last_student)
                {
                   last_student->pnextstudent=temp->pnextstudent;
                }
                else
                {
                    head=temp->pnextstudent;
                }
            free(temp);
			printf("\n  id of %d is deleted\n\n",id);
			return 1;
            }
			last_student=temp;
			temp=temp->pnextstudent;
		}
	}
	printf("\n\nthis id is not found in student data\n\n");
	return 0;

}
int delete_All()
{
	pstudent temp=head;
	if(head==NULL){
		printf("\n\n empty list\n\n");
		return 1;
	}
	while(head)
	{
		temp=head;
		head=head->pnextstudent;
		free(temp);
	}
	printf("\n\n all student are deleted \n\n");
	system("pause");
    return 1;
}
void displsy_student()
{
	pstudent temp=head;
	if(head==NULL)
        printf("\n\n                        * the list is empty *\n");
	else
		printf("\n\n                        * the list is *\n");
        printf("                      ************************* \n");
        printf(" ID\t\t\tname\t\t\theight\n********************************************************\n");
		while(temp!=NULL)
		{
			printf(" %d\t\t\t%s\t\t\t%.2f\n",
			temp->id,
			temp->name,
			temp->height);
			temp=temp->pnextstudent;
		}
		puts("\n");
}
void search_student()
{
	if(head==NULL)
	   printf("\n the list is empty ");
	else
	{
	   pstudent temp=head;
	   int id;
	   printf("\n enter the id you want to search: ");
	   scanf("%d",&id);
	   fflush(stdin);
	   if (temp->id==id){
		   printf("\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
	       system("pause");}
	   else{
	   while(temp && temp->id!=id)
	   {
	   	temp=temp->pnextstudent;
	   }
	   if(temp)
	    {
	   	 printf("\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
		 system("pause");
	    }
	    else
	   	 printf("\n not found this student id try another id later\n\n");
	   }
	}
}
void updata_student()
{
	if(head==NULL)
	   printf("\n the list is empty /n/n");
	else
	{
	   pstudent temp=head;
	   int id;
	   printf("\n enter the id you want to search: ");
	   scanf("%d",&id);
	   fflush(stdin);
	   if (temp->id==id)
	   {
		   printf("\n before update\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
		   printf("\n enter your update: \n");
		   full_the_record(temp);
		   printf("\n after update\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
		   system("pause");
	   }
	   else{
	   while(temp && temp->id!=id)
	   {
	   	temp=temp->pnextstudent;
	   }
	   if(temp)
	    {
           printf("\n before update\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
		   printf("\n enter your update: \n");
		   full_the_record(temp);
		   printf("\n after update\n id of student is: %d\n name of student is: %s\n the height is: %.2f\n\n",temp->id,temp->name,temp->height);
		   system("pause");
	    }
	    else{
	   	 printf("\n not found this student id try another id later\n\n");
		 system("pause");
		}
	   }
	}

}
int get_id()
{
	pstudent temp=head;
	int index,count=0;
	printf("\n enter the index you want to show its id: ");
	scanf("%d",&index);
	fflush(stdin);
	while(get_length()<index){
	printf("\n your index is't exist. Enter new index you want to show its id: ");
	scanf("%d",&index);
	fflush(stdin);
	}
	while(temp && count!=index-1)
	{
		count+=1;
		temp=temp->pnextstudent;
	}
	printf("\n  the id of this index is %d \n\n",temp->id);
	system("pause");
return 1;
}
int get_length()
{
	int count=0;
	pstudent temp=head;
	while(temp){
		count+=1;
		temp=temp->pnextstudent;
	}
	return count;
}
void Add_student_fromfile()
{
	FILE *f;
	int i=1;
	state=1;
	char*ptr;
	char line[1024];
	if((f=fopen("pop.csv","r"))==NULL)
        printf("file not found");
    while(fgets(line, sizeof line, f) !=NULL){
     if ((strlen(line)>0) && (line[strlen (line) - 1] == '\n'))
        line[strlen (line) - 1] = '\0';
     ptr=strtok(line,",");
     id=atoi(ptr);
     ptr=strtok(NULL,",");
     strcpy(name, ptr);
     ptr=strtok(NULL,",");
     height=atof(ptr);
     if(i==1) i=0;
     else
	 Add_student();
    }
	printf("\n     * all students from file are inserted *   \n\n\n");
	fclose(f);

}
void write_into_file()
{
	pstudent temp=head;
	FILE *f=fopen("pop.csv","w+");
    if(f==NULL)
       printf("file not found");
    else{
	  fprintf(f,"ID,Name,height\n");
	  while(temp){
         fprintf(f,"%d,%s,%.2f\n",temp->id,temp->name,temp->height);
         temp=temp->pnextstudent;
	    }
	  }
	  fclose(f);
}
