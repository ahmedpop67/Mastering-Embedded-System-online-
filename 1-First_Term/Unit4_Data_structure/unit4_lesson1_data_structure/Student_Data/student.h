/*
 * student.h
 *
 *  Created on: Jul 3, 2023
 *      Author: Egypt_Laptop
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct student{
	int id;
	char name[50];
	float height;
	struct student *pnextstudent;
}student;

typedef student * pstudent;

void full_the_record(pstudent new_student);
void Add_student();
int delete_student();
int id_is_exist(pstudent *head,int id);
int delete_All();
void displsy_student();
void search_student();
void updata_student();
int get_id();
int get_length();
int instr(void);
void Add_student_fromfile();
void write_into_file();

#endif /* STUDENT_H_ */
