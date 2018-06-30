#include"student.h"
void copy_stu(PNODE p,PNODE q)
{
	int i = 0;
	int t_number;
	char t_name[8];
	int t_age;
	double t_score;
	double t_sum;
	double t_average;
	int t_index;
	t_number = p->number;
	p->number = q->number;
	q->number =  t_number;
	strcpy(t_name,p->name);
	strcpy(p->name,q->name);
	strcpy(q->name,t_name);
	t_age = p->age;
	p->age = q->age;
	q->age = t_age;
	for(i = 0;i< 3;i++)
	{
		t_score = p->score[i];
		p->score[i] = q->score[i];
		q->score[i] = t_score;
	}
	t_sum = p->sum;
	p->sum = q->sum;
	q->sum = t_sum;
	t_average = p->average;
	p->average =  q->average;
	q->average = t_average;
	t_index = p->index;
	p->index = q->index;
	q->index = t_index;
	return;
	
}
