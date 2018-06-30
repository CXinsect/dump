#include"student.h"
void read_stu(void)
{
	FILE *fp;
	int i,m;
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
		printf("the file read is empty\n");
		printf("Please enter the data first\n");
		m = menu();
		select_stu(m);
	}
	if(!feof(fp))
	{
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
	printf("\t\t*********1.delate student information****************\n");
	printf("\t\t*********2.modief student information****************\n");
	printf("\t\t*********3.insert student information****************\n");
	printf("\t\t*********4.find   student information****************\n");
	printf("\t\t*********5.sort   student information****************\n");
	printf("\t\t*********6.save   student information****************\n");
	printf("\t\t*********7.traverse student information**************\n");
	scanf("%d",&m);
	while(1)
	{
		if(m > 0 && m <= 7)
			break;
		else
		{
			printf("your choice is wrong ,please enter (1 - 7)\n");
			scanf("%d",&m);
		}
	}
	while(1)
	{

		switch(m)
		{
		case 1:
  			delate_stu(pHead);
			break;
		case 2:
		        modief_stu(pHead);
		       break;
		case 3:
		       insert_stu(pHead);
		       break;
		case 4:
			find_stu(pHead);
		       break;
		case 5:
		       sort_stu(pHead);
		       break;
		case 6:
		       save_stu(pHead);
		       break;
		case 7:
		       traverse_stu(pHead);
		       break;
		default:
		       printf("error\n");
			       break;
		}
	while(getchar() != '\n')
		continue;
	printf("\t\t*********1.delate student information****************\n");
	printf("\t\t*********2.modief student information****************\n");
	printf("\t\t*********3.insert student information****************\n");
	printf("\t\t*********4.find   student information****************\n");
	printf("\t\t*********5.sort   student information****************\n");
	printf("\t\t*********6.save   student information****************\n");
	printf("\t\t*********7.traverse student information**************\n");
	printf("Are your want to be Continued.....?(Y-N)\n");
	scanf("%c",&ch);
		if( ch == 'N' || ch == 'n')
			break;
		printf("please enter your choice\n");
		scanf("%d",&m);
		if(m < 0 || m > 7)
		{
		printf("your choice is wrong ,please enter (1 - 7)\n");
		scanf("%d",&m);
		}
	}
	}
	else
		return;
	}
	else{
		printf("please enter the date first\n");
		m = menu();
		select_stu(m);
	}
	return;
}
