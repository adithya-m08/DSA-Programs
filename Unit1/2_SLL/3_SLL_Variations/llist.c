#include<stdio.h>
#include"llist.h"

int main()
{
	NODE *head=NULL;
	
	int choice,ele;
	do{
		printf("1.Insert Front 2. display 3.Insert Front\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an element\n");
					scanf("%d",&ele);
					head=insertFront(head,ele);
					break;
			case 2:display(head);
					break;
			case 3:printf("Enter an element\n");
					scanf("%d",&ele);
					insertFront1(&head,ele);
					break;
		}
	}while(choice<4);
	head=destroyList(head);
	return 0;
}