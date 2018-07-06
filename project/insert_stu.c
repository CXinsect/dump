#include"student.h"
void  insert_stu(PNODE pH)
{
	printf("If you haven't add any information please use file to add\n");
	char t;
	int i;
	int  ch;
	PNODE r = pH;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL)
	{
		printf("The memory assighing is failed");
		exit(1);
	}
	else
	{
		pNew->index = 0;
	 		if(pH == NULL)
			{
				printf("please enter the data first\n");
				return;
			}	
        		PNODE p = pH->pRight;
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
			}
			pNew->average = pNew->sum / 3.0;
	                pNew->index = getindexs(pH,pNew->sum);
			PNODE w = pH->pRight;
		/*	while(w != pH)
			{
				if(w->sum < pNew->sum)
					w->index++;
				w = w->pRight;
			}	*/
		       while( p->pRight != pH)
			       p = p->pRight;
		       pNew->pRight = p->pRight;
		       p->pRight = pNew;
		       pNew->pLeft = p;
		       PNODE r = p->pRight;
		       r->pLeft = pNew;
	}

}
