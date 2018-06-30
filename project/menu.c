#include"student.h"
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
			printf("your choice is wrong ,please enter (1 - 10)\n");
			scanf("%d",&choice);
		}
	}
	while(getchar() !='\n')
		continue;
	return choice;
}
