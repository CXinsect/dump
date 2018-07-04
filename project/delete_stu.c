#include"student.h"
void delate_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	PNODE p = pH->pRight;
	PNODE r = pH->pRight;
	int type,i;
	char name[8],ch;
	int index;
	int number,flag = 0;
	int f1,f3;char f2[8];
	printf("please enter your type for finding\n");
	printf("**1.with number\n");
	printf("**2.with name  \n");
	printf("**3.with index \n");
	scanf("%d",&type);
	if(type == 1)
	{
		printf("please enter the number\n");
		scanf("%d",&f1);
		while( p != pH)
		{
			if(p->number ==  f1){
				flag= 1;
			       show_table();
                               printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		               for(i = 0;i<3;i++)
			       printf("%.0lf\t",p->score[i]);
		               printf("%.0lf\t%.0lf\t%d",p->sum,p->average,p->index);
			       while(getchar() != '\n')
				       continue;
			       printf("\n");
		              printf("Are you sure to delate this people(Y or N)\n");
			      scanf("%c",&ch);
			      if( ch == 'y' || ch == 'Y')
			      {
				      PNODE k = pH->pRight;
				      while( k != p )
				      {
					      if(p->sum > k->sum)
						      k->index--;
					      k = k->pRight;
				      }
				    PNODE q = p->pLeft;
				    PNODE r = p->pRight;
				    q->pRight = p->pRight;
				    r->pLeft = p->pLeft;
				    free(p);
			      }
	                      		      
			}
			p = p->pRight;
		}
		if(flag == 0)
			printf("No people\n");
	}
	if(type == 2)
	{
		while(getchar() != '\n')
			continue;
		printf("please enter the name\n");
		scanf("%s",f2);
		while( p!=pH)
		{
			if(strcmp(p->name,f2) == 0)
			{
				show_table();
				flag = 2;
    		printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		for(i = 0;i<3;i++)
			printf("%.0lf\t",p->score[i]);
		printf("%.0lf\t%.0lf\t%d",p->sum,p->average,p->index);
		              while(getchar() !='\n')
				      continue;
			      printf("\n");
		              printf("Are you sure to delate this people(Y or N)\n");
			      scanf("%c",&ch);
			      if( ch == 'y' || ch == 'Y')
			      {
				      PNODE k = pH->pRight;
				      while( k != p )
				      {
					      if(p->sum > k->sum)
						      k->index--;
					      k = k->pRight;
				      }
				    PNODE q = p->pLeft;
				    PNODE r = p->pRight;
				    q->pRight = p->pRight;
				    r->pLeft = p->pLeft;
				    free(p);
			      }

 			}
			p = p->pRight;
		
		}
		if(flag == 0)
			printf("No people\n");
	}
	if(type == 3)
	{
		printf("please enter the index\n");
		scanf("%d",&f3);
		while( p!= pH)
		{
			if(p->index == f3)
			{
				show_table();
				flag = 3;
    		printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		for(i = 0;i<3;i++)
			printf("%.0lf\t",p->score[i]);
		printf("%.0lf\t%.0lf\t%d",p->sum,p->average,p->index);
		while(getchar() != '\n')
			continue;
		printf("\n");
		              printf("Are you sure to delate this people(Y or N)\n");
			      scanf("%c",&ch);
			      if( ch == 'y' || ch == 'Y')
			      {
				      PNODE k = pH->pRight;
				      while( k != p )
				      {
					      if(p->sum > k->sum)
						      k->index--;
					      k = k->pRight;
				      }
				    PNODE q = p->pLeft;
				    PNODE r = p->pRight;
				    q->pRight = p->pRight;
				    r->pLeft = p->pLeft;
				    free(p);
			      }
			}
			p = p->pRight;
		}
		if(flag == 0)
			printf("No people\n");
	}
	return;
}
