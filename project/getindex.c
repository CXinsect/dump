#include"student.h"
int getindex (PNODE pH,double sum)
{
	int i,count = 1;
	PNODE p = pH->pRight;
	for(;p->pRight!= NULL;p = p->pRight){
		if(p->sum < sum)
			p->index++;
		if(p->sum > sum)
			count++;
	}
	return count;

}
