#include"student.h"
PNODE  append_stu(void)
{
	PNODE pHead = (PNODE )malloc(sizeof(NODE));
	int i;
	char ch,t;
	PNODE pNew = NULL;
	if(pHead == NULL)
	{
		printf("The memory is assigned wrong!\n");
		exit(1);
     	}
	else
	{
		pHead->pLeft = NULL;
		pHead->pRight = NULL;
		PNODE pTail = pHead;
		while(1)
		{
		        pNew = (PNODE)malloc(sizeof(NODE));
			pNew->sum = 0;
			if(pNew == NULL)
                      	{
	         	printf("The memory is assigned wrong!\n");
		        exit(1);
			}
			printf("number\n");
			scanf("%d",&pNew->number);
			printf("name\n");
			scanf("%s",pNew->name);
			while(t=getchar() != '\n')
				continue;
			printf("sex\n");
			scanf("%c",&pNew->gender);
			for(i = 0;i<3;i++)
			{
				printf("please enter %s 's score\n",subject[i]);
				scanf("%lf",&pNew->score[i]);
				pNew->sum += pNew->score[i];
				pNew->average = pNew->sum / 3.0;
			}
			pTail->pRight = pNew;
			pNew->pLeft = pTail;
			pNew->pRight = NULL;
			pTail = pNew;
			pNew->index = getindex(pHead,pNew->sum);
			while(t =getchar() != '\n')
				continue;
			printf("continue?(Y or N)\n");
			scanf("%c",&ch);
			if(ch == 'N' || ch == 'n')
				break;
                    }
                        pHead->pLeft = pNew;
			pTail->pRight = pHead;
	}
			return pHead;
}
