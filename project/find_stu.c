#include"student.h"
void find_stu(PNODE pH)
{
	if( pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	PNODE p = pH->pRight;
	int type,i;
	char name[8];
	int index;
	int number,flag = 0;
	int f1,f3;char f2[8];
	printf("**1.with number\n");
	printf("**2.with name  \n");
	printf("**3.with index \n");
	while(1)
	{
	if(type != 1 || type != 2 || type != 3){
		printf("The data is wrong,please enter again\n");
		scanf("%d",&type);
		break;
	}
	}
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
			}
			p = p->pRight;
		}
		if(flag == 0)
			printf("No people\n");
	}
	return;
}
