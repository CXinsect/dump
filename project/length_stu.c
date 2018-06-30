#include"student.h"
int length_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return 0;
	}
	PNODE p = pH->pRight;
	int count = 0;
	while( p!=pH)
	{
		p = p->pRight;
		count++;
	}
	return count;
}
