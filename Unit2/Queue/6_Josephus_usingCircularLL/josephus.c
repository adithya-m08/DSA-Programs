//Josephus problem using circular linked list
#include<stdio.h>
#include"josephus.h"

int main()
{
	LIST l;
	int start,skip;
	
	initQueue(&l);
	createQueue(&l);
	display(&l);
	printf("Enter start value and skip value\n");
	scanf("%d%d",&start,&skip);
	printf("Winner is %d\n",winner(&l,start,skip));
	return 0;
}