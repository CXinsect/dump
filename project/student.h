#ifndef __STUDENT__H__
#define __STUDENT__H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#include<ctype.h>
typedef struct list{
	int number;
	char name[8];
	char gender;
	int age;
	double score[3];
	double sum;
	double average;
   	 int index;
	struct list *pLeft,*pRight;
}NODE,*PNODE;
extern char *subject[3];
int menu(void);
PNODE append_stu(void);
void logout(void);
int getch(void);
void select_menu(void);
void delate_stu(PNODE);
void save_stu(PNODE);
void read_stu(void);
void  insert_stu(PNODE);
void file_append(void);
void find_stu(PNODE);
void exit_stu(PNODE);
void sort_stu(PNODE);
void modief_stu(PNODE);
int getindex(PNODE,double);
int getindexs(PNODE,double);
void traverse_stu(PNODE);
void show_table(void);
void select_stu(int);
int  length_stu(PNODE p);
void copy_stu(PNODE,PNODE);
#endif
