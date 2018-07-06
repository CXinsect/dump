#include"student.h"
void sort_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	int i,j;
	int t;
	PNODE p= NULL,q = NULL;
	int m = length_stu(pH);
	for(i = 0,p = pH->pRight;i<m-1;i++,p = p->pRight)
	{
		for(j = i+1,q = p->pRight;j< m;j++,q = q->pRight)
		{
			if(p->sum < q->sum)
			{
				copy_stu(p,q);
			       
			}
		}
	}
	return;
}
