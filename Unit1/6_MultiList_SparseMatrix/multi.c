#include<stdio.h>
#include"multi.h"
int main()
{
	LIST *pl;
	
	initList(&pl);
	createList(&pl);
	display(&pl);
	
	return 0;
}