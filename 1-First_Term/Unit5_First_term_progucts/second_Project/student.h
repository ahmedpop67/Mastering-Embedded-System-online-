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


typedef struct student_info{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[5];
	//student_info *next;
}stinfo;

typedef struct FIFO
{
	unsigned int count;
	unsigned int length;
	stinfo* base;
	stinfo* head;
	stinfo* tail;
}FIFO_BUF_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_status;

void full_the_record();
void Add_student();
int delete_student();
//int id_is_exist(pstudent *head,int id);
int delete_All();
//void displsy_student();
void search_student_by_rollnum();
void search_student_by_fname();
void search_student_by_cid();
void updata_student();
int get_length();
int instr(void);
void Add_student_fromfile();
void write_into_file();


#endif
