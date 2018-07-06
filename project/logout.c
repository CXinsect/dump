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
		if((fp1 = fopen("/tmp/temp","at")) == NULL)
		{
			printf("The file opening is wrong\n");
			return;
		}
		if((fp2 = fopen("/tmp/temp1","at")) == NULL)
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
		//	fwrite(&mm[i],sizeof(char),1,fp2);
			fprintf(fp2,"%c",mm[i]);
		}
			fputc('\n',fp2);
           	 fprintf(fp1,"%s",name);
		 fputc('\n',fp1);
		 printf("\n");
		fclose(fp1);
		fclose(fp2);
		read_stu();
	}
	else
	{
		if((fp1 = fopen("/tmp/temp","rt")) == NULL)
		{
		printf("The file opening is wrong\n");
		return;
		}
		if((fp2 = fopen("/tmp/temp1","rt")) == NULL)
		{
			printf("The file opening is wrong\n");
			return;
		}
		printf("please enter the user name\n");
		scanf("%s",name);
		while(!feof(fp1))
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
						while(!feof(fp2))
						{
				    			 fscanf(fp2,"%s",m);
						  	 if(strcmp(mm,m) == 0)
						 	  {
								       printf("The code is right\n");
									fclose(fp1);
									fclose(fp2);
									read_stu();
			   		       	 	  } 
						   	else
								   continue;
						}
						if(feof(fp2))
						{	
							printf("The code is wrong\n");
							exit(1);
						}
			}
			else
				continue;
		}
		if(feof(fp1))
		{
			printf("You are a new member\n");
			exit(1);
		}
	}

}

