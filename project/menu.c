#include"student.h"
int menu(void)
{
	int choice;
	printf("========================================================================\n");
	printf("=\t\t\tThis is a student managerment System\t\t=\n");
	printf("=\t\t\t1.Add    student information\t\t\t=\n");
	printf("=\t\t\t2.delete student information\t\t\t=\n");
	printf("=\t\t\t3.modify student information\t\t\t=\n");
	printf("=\t\t\t4.insert student information\t\t\t=\n");
	printf("=\t\t\t5.search student information\t\t\t=\n");
	printf("=\t\t\t6.sort   student information\t\t\t=\n");
	printf("=\t\t\t7.save   student information\t\t\t=\n");
	printf("=\t\t\t8.read   student information\t\t\t=\n");
	printf("=\t\t\t9.clear  student information\t\t\t=\n");
	printf("=\t\t\t10.traverse-student-information\t\t\t=\n");
	printf("=\t\t\t11.login-----out------ystem \t\t\t=\n");
        printf("=\t\t\tplease enter your choices (1 - 11)\t\t=\n");
	printf("==========================================================================\n");
	printf("Please enter your choice.....\n");
	scanf("%d",&choice);
	while(1)
	{
		if(choice > 0 && choice <= 11)
			break;
		else
		{
			printf("your choice is wrong ,please enter (1 - 11)\n");
			scanf("%d",&choice);
		}
	}
	return choice;
}
