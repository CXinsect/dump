#include"student.h"
void logout(void)
{
	FILE *fp1,*fp2;
	char name[8];
	char mm[9];
	char st[8];
	char m[9];
	int i,c;
	char ch;
	printf("Do you a new member?(Y-N)\n");
	scanf("%c",&ch);
	if( ch == 'Y' || ch == 'y')
	{
		if((fp1 = fopen("/tmp/temp","w")) == NULL)
		{
			printf("The file opening is wrong\n");
			return;
		}
		if((fp2 = fopen("/tmp/temp1","w")) == NULL)
		{
			printf("The file opening is wrong\n");
			return;
		}
		printf("Please enter your user name\n");
		scanf("%s",name);
		while(getchar() != '\n')
			continue;
		printf("Please enter the safe codes(8 bits)\n");
		for(i = 0;i<9;i++)
		{
			ch  = getch();
			if(mm[i] == '\x0d')
			{
			mm[i] = '\0';
			break;
			}
			mm[i] = ch;
	   	 fwrite(&mm[i],sizeof(char),1,fp2);
		}
           	 fprintf(fp1,"%s",name);
		 printf("\n");
		c =  menu();
		select_stu(c);
	}
	else
	{
		if((fp1 = fopen("/tmp/temp","r")) == NULL)
		{
		printf("The file opening is wrong\n");
		return;
		}
		if((fp2 = fopen("/tmp/temp1","r")) == NULL)
		{
			printf("The file opening is wrong\n");
			return;
		}
		printf("please enter the user name\n");
		scanf("%s",name);
		while(!feof(fp1) && !feof(fp2))
		{
			fscanf(fp1,"%s",st);
			if(strcmp(st,name) == 0)
			{
		           fscanf(fp2,"%s",m);
			   while(getchar() != '\n')
				   continue;
                           printf("please enter the safe code(8 bits)\n");
				for(i = 0;i<9;i++)
				{
				mm[i] = getch();
				if(mm[i] == '\x0d')
				{
				mm[i] = '\0';
				break;
				}
				putchar('*');
				}
			   if(strcmp(mm,m) == 0){
				read_stu();
			   }
			   else
			   {
				   printf("The code is wrong\n");
				   fclose(fp1);
				   fclose(fp2);
				   exit(1);
			   }
			}
			fscanf(fp1,"%s",st);
		}
		fclose(fp1);
		fclose(fp2);
	}

}
