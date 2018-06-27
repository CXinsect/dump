#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	int number;
	char name[8];
	char gender;
	int age;
	double score[3];
	double sum;
	double average;
	int index;
	struct List *pLeft,*pRight;
}NODE,*PNODE;
char *subject[] = {"chinese","math","english"};
int count_stu = 0;
int menu(void);
PNODE append_stu(void);
void delate_stu(PNODE);
void save_stu(PNODE);
void read_stu(void);
void insert_stu(PNODE);
void file_append(void);
void find_stu(PNODE);
void exit_stu(PNODE);
void sort_stu(PNODE);
void modief_stu(PNODE);
int getindex(PNODE,double);
void traverse_stu(PNODE);
void show_table(void);
void select_stu(int);
int  length_stu(PNODE p);
void copy_stu(PNODE,PNODE);
int main (int argc ,char * argv[])
{
	int c;
	int m = menu();
	select_stu(m);
	return 0;
}
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
			pNew->index = getindex(pHead,pNew->sum);
			count_stu++;
			pTail->pRight = pNew;
			pNew->pLeft = pTail;
			pNew->pRight = NULL;
			pTail = pNew;
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
int menu(void)
{
	int choice;
	printf("==========================================================================\n");
	printf("\t\t************This is a system for student*************\n");
	printf("\t\t***************You Can modeif this*******************\n");
	printf("\t\t*********1.append student information****************\n");
	printf("\t\t*********2.delate student information****************\n");
	printf("\t\t*********3.modief student information****************\n");
	printf("\t\t*********4.insert student information****************\n");
	printf("\t\t*********5.find   student information****************\n");
	printf("\t\t*********6.sort   student information****************\n");
	printf("\t\t*********7.save   student information****************\n");
	printf("\t\t*********8.read   student information****************\n");
	printf("\t\t*********9.traverse student information**************\n");
	printf("\t\t*********10.logoue out*******************************\n");
        printf("\t\t***************please enter your choices (1 - 10)*****************8\n");
	printf("==========================================================================\n");
	printf("Any Number button to continue.....\n");
	scanf("%d",&choice);
	while(1)
	{
		if(choice > 0 && choice <= 10)
			break;
		else
		{
			printf("your choice is wrong ,please enter (1 - 9)\n");
			scanf("%d",&choice);
		}
	}
	while(getchar() !='\n')
		continue;
	return choice;
}
void traverse_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	PNODE p = pH->pRight;
	show_table();
	int i;
	while(p != pH)
	{
    		printf("%d\t%s\t%c\t",p->number,p->name,p->gender);
		for(i = 0;i<3;i++)
			printf("%.0lf\t",p->score[i]);
		printf("%.0lf\t%.0lf\t%d",p->sum,p->average,p->index);
		p = p->pRight;
		printf("\n");
	}
	return;
}
void show_table(void)
{
	int i;
	printf("number\tname\tsex\t");
	for(i = 0;i < 3;i++)
		printf("%s\t",subject[i]);
	printf("sum\taverage\tindex\n");
	return;
}
void select_stu(int c)
{
	PNODE pHead = NULL;
	PNODE p = NULL;
	char ch;
	while(1){
	switch(c)
	{
		PNODE p = NULL;
		case 1:
			pHead = append_stu();
			p = pHead;
			break;
		case 2:
  			delate_stu(pHead);
			break;
		case 3:
		        modief_stu(pHead);
		       break;
		case 4:
		        insert_stu(pHead);
		       break;
		case 5:
			find_stu(pHead);
		       break;
		case 6:
		       sort_stu(p);
		       break;
		case 7:
		       save_stu(pHead);
		       break;
		case 8:
		       read_stu();
		       break;
		case 9:
		       traverse_stu(pHead);
		       break;
		case 10:
		       exit_stu(pHead);
		       break;
		default:
		       printf("error\n");
		       break;
	}
	menu();
	printf("Are your want to be Continued.....?(Y-N)\n");
	scanf("%c",&ch);
	if( ch == 'N' || ch == 'n')
		break;
	printf("please enter your choice\n");
	scanf("%d",&c);
	if(c < 0 || c > 10)
	{
	printf("your choice is wrong ,please enter (1 - 10)\n");
	scanf("%d",&c);
	}
	while(getchar() != '\n')
		continue;
	}

}
int getindex (PNODE pH,double sum)
{
	int i,count = 1;
	PNODE p = pH->pRight;
	for(i= 0;i<count_stu && p != pH;i++,p = p->pRight){
		if(p->sum < sum)
			p->index++;
		if(p->sum > sum)
			count++;
	}
	return count;

}
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
void exit_stu(PNODE pH)
{
		exit(0);
}
void save_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
	}
	FILE *fp;
	PNODE p = pH->pRight;
	int i;
	printf("please enterthe file name\n");
	if((fp = fopen("/tmp/test1","w")) == NULL)
	{
		printf("the file opne is wrong\n");
		exit(0);
	}
	while( p!= pH){
	fwrite(p,sizeof(NODE),1,fp);
	p = p->pRight;
	}
	printf("%d  pieces of message have been written\n",count_stu);
	fclose(fp);
}
void read_stu(void)
{
	char filename[15];
	FILE *fp;
	int i;
	long pos;
	char ch;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	PNODE pNew = NULL;
	if(pHead == NULL)
	{
		printf("The memory assigned is failed\n");
		exit(1);
	}
	if((fp = fopen("/tmp/test1","r")) == NULL)
	{
		printf("the file read is wrong\n");
		exit(0);
	}
	pHead->pLeft = NULL;
	pHead->pRight = NULL;
	PNODE pTail = pHead;
	pNew = (PNODE)malloc(sizeof(NODE));
	fread(pNew,sizeof(NODE),1,fp);
	while(!feof(fp)){
		pTail->pRight = pNew;
		pNew->pLeft = pTail;
		pNew->pRight = NULL;
		pTail = pNew;
		pos = ftell(fp);
		pNew = (PNODE)malloc(sizeof(NODE));
		fseek(fp,pos,0);
		fread(pNew,sizeof(NODE),1,fp);
	}
	pHead->pLeft = pNew;
	pTail->pRight = pHead;
	fclose(fp);
	traverse_stu(pHead);
	printf("If you want to change information in the file(y - n)\n");
	scanf("%c",&ch);
	if( ch == 'Y' || ch == 'y'){
		modief_stu(pHead);
	        save_stu(pHead);
	}
	else
		return;
	return;
}
void insert_stu(PNODE pH)
{
	printf("If you haven't add any information please use file to add\n");
	char t;
	int i;
	int  ch;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL)
	{
		printf("The memory assighing is failed");
		exit(1);
	}
	else
	{
		printf("The type that you want to add users\n");
		printf("1.Don't use the file\n");
		printf("2.Use the file\n");
		printf("Please enter the choice\n");
		scanf("%d",&ch);
		if(ch == 1){
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
				pNew->average = pNew->sum / 3.0;
			}
	                pNew->index = getindex(pH,pNew->sum);	
		       while( p->pRight != pH)
			       p = p->pRight;
		       pNew->pRight = p->pRight;
		       p->pRight = pNew;
		       pNew->pLeft = p;
		       PNODE r = p->pRight;
		       r->pLeft = pNew;}
		else
			file_append();
		       return;
	}
}
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
			       while(getchar() != '\n')
				       continue;
			       printf("\n");
		              printf("Are you sure to delate this people(Y or N)\n");
			      scanf("%c",&ch);
			      if( ch == 'y' || ch == 'Y')
			      {
				    PNODE q = p->pLeft;
				    PNODE r = p->pRight;
				    q->pRight = p->pRight;
				    r->pLeft = p->pLeft;
				    free(p);
			      }
			      for(i = 0;i<count_stu;i++,r = r->pRight)
			      {
				      if(p->index < r->index)
					      r->index--;
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
	int number,flag = 0;
	int f1,f3;char f2[8];
	char ch,t;
	printf("please enter your type for finding\n");
	printf("**1.with number\n");
	printf("**2.with name  \n");
	printf("**3.with getindex \n");
	while(getchar() != '\n')
		continue;
	scanf("%d",&type);
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
				p->average = p->sum / 3.0;
			}
			p->index = getindex(pH,p->sum);
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
				p->average = p->sum / 3.0;
			}
				p->index = getindex(pH,p->sum);
 			}
			p = p->pRight;
		
		}
		if(flag == 0)
			printf("No people\n");
	}
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
				p->average = p->sum / 3.0;
			}
			p->index = getindex(pH,p->sum);
			}
			p = p->pRight;
		}
		if(flag == 0)
			printf("No people\n");
		}
	}

}
int length_stu(PNODE pH)
{
	if(pH == NULL)
	{
		printf("please enter the data first\n");
		return;
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
void copy_stu(PNODE p,PNODE q)
{
	int i = 0;
	int t_number;
	char t_name[8];
	int t_age;
	double t_score;
	double t_sum;
	double t_average;
	int t_index;
	t_number = p->number;
	p->number = q->number;
	q->number =  t_number;
	strcpy(t_name,p->name);
	strcpy(p->name,q->name);
	strcpy(q->name,t_name);
	t_age = p->age;
	p->age = q->age;
	q->age = t_age;
	for(i = 0;i< 3;i++)
	{
		t_score = p->score[i];
		p->score[i] = q->score[i];
		q->score[i] = t_score;
	}
	t_sum = p->sum;
	p->sum = q->sum;
	q->sum = t_sum;
	t_average = p->average;
	p->average =  q->average;
	q->average = t_average;
	t_index = p->index;
	p->index = q->index;
	q->index = t_index;
	return;
	
}
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
			if(p->index > q->index)
			{
				copy_stu(p,q);
			       
			}
		}
	}
	return;
}
void file_append(void)
{
	FILE *fp;
	int i;
	PNODE pHead = (PNODE )malloc(sizeof(NODE));
	char ch,t;
	PNODE pNew;
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
			pNew->index = getindex(pHead,pNew->sum);
			count_stu++;
			pTail->pRight = pNew;
			pNew->pLeft = pTail;
			pNew->pRight = NULL;
			pTail = pNew;
			while(t =getchar() != '\n')
				continue;
			printf("continue?(Y or N)\n");
			scanf("%c",&ch);
			if(ch == 'N' || ch == 'n')
				break;
                    }
                        pHead->pLeft = pNew;
			pTail->pRight = pHead;
			save_stu(pHead);
	}
	return;
}
