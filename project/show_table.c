#include"student.h"
void show_table(void)
{
	int i;
	printf("number\tname\tsex\t");
	for(i = 0;i < 3;i++)
		printf("%s\t",subject[i]);
	printf("sum\taverage\tindex\n");
	return;
}
