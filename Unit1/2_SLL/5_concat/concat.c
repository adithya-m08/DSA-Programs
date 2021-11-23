
#include"llist.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n,ele;
	NODE *head1=NULL,*head2=NULL,*head3=NULL;
	printf("List1 nodes\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ele);
		head1=insertBeg(head1,ele);
	}
	display(head1);
	printf("List2 nodes\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ele);
		head2=insertBeg(head2,ele);
	}
	display(head2);
	head3=concat(head1,head2);
	printf("main\n");
	display(head3);
	head1=destroyList(head1);
	head2=destroyList(head2);
	//Do not call destroylist on head3
	//It points to list1 which is already destroyed
	//If head3 was passed as an argument to concat
	//then calling destroyList on head3 would be required
	return 0;
}