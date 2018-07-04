#include"student.h"
void select_stu(int c)
{
	PNODE pHead = NULL;
	char ch;
	while(1)
	{
		switch(c)
		{
			case 1:
				pHead = append_stu();
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
			       sort_stu(pHead);
			       break;
			case 7:
			       save_stu(pHead);
			       break;
			case 8:
			       read_stu();
			       break;
			case 9:
			       clear(pHead);
			       break;
			case 10:
			       traverse_stu(pHead);
			       break;
			case 11:
			       exit_stu(pHead);
			       break;
			default:
			       printf("error\n");
			       break;
		}
		c = menu();
		printf("Are your want to be Continued.....?(Y-N)\n");
		while(getchar() != '\n')
			continue;
		scanf("%c",&ch);
		if( ch == 'N' || ch == 'n')
			break;
		if(c < 0 || c > 11)
		{
			printf("your choice is wrong ,please enter (1 - 11)\n");
			scanf("%d",&c);
		}
	}
/*	while(getchar() != '\n')
		continue;*/

}
