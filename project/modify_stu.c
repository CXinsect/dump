#include"student.h"
void modief_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	PNODE p = pH->pRight;
	int type,index,i;
	char name[8];
	int number,flag = 0,m;
	int f1,f3;char f2[8];
	char ch,t;
	printf("please enter your type for finding\n");
	printf("**1.with number\n");
	printf("**2.with name  \n");
	printf("**3.with getindex \n");
	scanf("%d",&type);
	while(1)
	{
		if(type == 1 || type == 2 || type == 3)
			break;
		else
		{
			printf("The data is wrong,please enter again\n");
			scanf("%d",&type);
		}
	}
	if(type == 1)
	{
		printf("please enter the number\n");
		scanf("%d",&f1);
		while( p != pH)
		{
			if(p->number ==  f1)
			{
				flag= 1;
			       show_table();
                               printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		               for(i = 0;i<3;i++)
			       printf("%.0lf\t",p->score[i]);
		               printf("%.0lf\t%.0lf\t%d\n",p->sum,p->average,p->index);
			       while(getchar() != '\n')
				       continue;
		       		printf("Are you sure to fix this information(y or no)\n");
		 		scanf("%c",&ch);
				if(ch == 'y' || ch == 'Y')
				{
					p->sum = 0;
					p->index = 0;
					printf("number\n");
					scanf("%d",&p->number);
					printf("name\n");
					scanf("%s",p->name);
					while(t=getchar() != '\n')
						continue;
					printf("sex\n");
					scanf("%c",&p->gender);
					for(i = 0;i<3;i++)
					{
						printf("please enter %s 's score\n",subject[i]);
						scanf("%lf",&p->score[i]);
						p->sum += p->score[i];
					}
						p->average = p->sum / 3.0;
			            	p->index = getindexs(pH,p->sum);
					PNODE k = pH->pRight;
					while(k != p)
					{
						if(k->sum < p->sum)
							k->index--;
						k = k->pRight;
					}
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
					printf("%.0lf\t%.0lf\t%d\n",p->sum,p->average,p->index);
					while(getchar() != '\n')
						continue;
			       		printf("Are you sure to fix this information(y or no)\n");
			 		scanf("%c",&ch);
					if(ch == 'y' || ch == 'Y')
					{
					p->sum = 0;
					p->index = 0;
						printf("number\n");
						scanf("%d",&p->number);
						printf("name\n");
						scanf("%s",p->name);
						while(t=getchar() != '\n')
							continue;
							printf("sex\n");
						scanf("%c",&p->gender);
						for(i = 0;i<3;i++)
						{
							printf("please enter %s 's score\n",subject[i]);
							scanf("%lf",&p->score[i]);
							p->sum += p->score[i];
						}
						p->average = p->sum / 3.0;
						p->index = getindexs(pH,p->sum);
						PNODE k = pH->pRight;
					while(k != p)
					{
						if(k->sum < p->sum)
							k->index--;
						k = k->pRight;
					}
					}
				}
				p = p->pRight;
			}
		if(flag == 0)
			printf("No people\n");
	}
	if(type == 3)
	{
		printf("please enter the getindex\n");
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
		       		printf("Are you sure to fix this information(y or no)\n");
		 		scanf("%c",&ch);
				if(ch == 'y' || ch == 'Y')
				{
					p->sum = 0;
					p->index = 0;
					p->sum = 0;
					p->index = 0;
					printf("number\n");
					scanf("%d",&p->number);
					printf("name\n");
					scanf("%s",p->name);
					while(t=getchar() != '\n')
						continue;
						printf("sex\n");
					scanf("%c",&p->gender);
					for(i = 0;i<3;i++)
					{
						printf("please enter %s 's score\n",subject[i]);
						scanf("%lf",&p->score[i]);
						p->sum += p->score[i];
					}
						p->average = p->sum / 3.0;
					p->index = getindexs(pH,p->sum);
					PNODE k = pH->pRight;
					while(k != p)
					{
						if(k->sum < p->sum)
							k->index--;
						k = k->pRight;
					}
				}
			}
			p = p->pRight;
		}
		if(flag == 0)
			printf("No people\n");
	}
}
