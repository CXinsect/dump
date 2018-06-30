#include"student.h"
void save_stu(PNODE pH)
{
	int count_stu = 0;
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
		++count_stu;
	fwrite(p,sizeof(NODE),1,fp);
	p = p->pRight;
	}
	printf("%d  pieces of message have been written\n",count_stu);
	fclose(fp);
}
