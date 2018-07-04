#include"student.h"
void clear(PNODE pHead)
{
	int m;
	char ch;
	if(pHead == NULL)
	{
		printf("Please enter the data first\n");
		m = menu();
		select_stu(m);
	}
	PNODE p = pHead->pRight;
	PNODE q = NULL;
	while(p != NULL)
	{
		q = p->pRight;
		free(p);
		p = q;
	}
	pHead = NULL;
	return;
}
