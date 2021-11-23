#include<stdio.h>
#include"llist.h"

int main()
{
	NODE *head1=NULL,*head2=NULL,*head3=NULL;
	int x;
	printf("Polynomial 1:\n");
	createPoly(&head1);
	display(head1);
	printf("Polynomial 2:\n");
	createPoly(&head2);
	display(head2);
	addPoly(head1,head2,&head3);
	display(head3);
	printf("Enter value of x\n");
	scanf("%d",&x);
	printf("Res=%d\n",evalPoly(head1,x));
	destroyList(&head1);
	destroyList(&head2);
	destroyList(&head3);
	return 0;
}