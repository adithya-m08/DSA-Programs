#include<stdio.h>
#include"llist.h"

int main()
{
	LLIST head1,head2,head3;
	initList(&head1);
	initList(&head2);
	initList(&head3);
	int x;
	printf("Polynomial 1:\n");
	createPoly(&head1);
	display(&head1);
	printf("Polynomial 2:\n");
	createPoly(&head2);
	display(&head2);
	addPoly(&head1,&head2,&head3);
	display(&head3);
	destroyList(&head1);
	destroyList(&head2);
	destroyList(&head3);
	return 0;
}