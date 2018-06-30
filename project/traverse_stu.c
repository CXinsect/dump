#include"student.h"
void traverse_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	PNODE p = pH->pRight;
	show_table();
	int i;
	while(p != pH)
	{
    		printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		for(i = 0;i<3;i++)
			printf("%.0lf\t",p->score[i]);
		printf("%.0lf\t%.0lf\t%d",p->sum,p->average,p->index);
		p = p->pRight;
		printf("\n");
	}
	return;
}
