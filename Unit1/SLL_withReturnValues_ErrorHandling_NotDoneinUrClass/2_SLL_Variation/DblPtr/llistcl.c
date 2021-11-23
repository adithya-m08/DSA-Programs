#include<stdio.h>
#include"llist.h"

int main()
{
	NODE* head;
	initList(&head);
	
	int choice,ele,pos,status;
	
	do{
		printf("1.Insert At Pos 2.DEleteAtPos 3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 3:display(head);
					break;
			
			case 2:printf("Enter the pos\n");
					scanf("%d",&pos);
					deleteAtPos(&head,&ele,pos,&status);
					if(status)
						printf("DEleted ele is %d\n",ele);
					else
						printf("Deletion Failed\n");
					break;
			case 1:printf("Enter the element\n");
					scanf("%d",&ele);
					printf("Enter the pos\n");
					scanf("%d",&pos);
					insertAtPos(&head,ele,pos,&status);
					if(status)
						printf("Inserted %d successfully\n",ele);
					else
						printf("Insertion failed\n");
					break;
		}
	}while(choice<4);
	destroyList(&head);
}