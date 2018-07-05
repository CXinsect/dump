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
	printf("This is a danger manner,Are you sure?(Y-N)\n");
	while(getchar() != '\n')
		continue;
	scanf("%c",&ch);
	if(ch != 'y' || ch != 'Y')
	{
		m = menu();
		select_stu(m);
	}
	while(p != pHead)
	{
		q = p->pRight;
		free(p);
		p = q;
	}
	pHead = NULL;
	return;
}
