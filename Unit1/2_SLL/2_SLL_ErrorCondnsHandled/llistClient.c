#include<stdio.h>
#include"llist.h"

int main()
{
	LLIST lobj;
	initList(&lobj);
	int choice,ele,pos;
	
	do{
		printf("1.Insert Front 2.Insert Last 3.Insert At Pos 4.Display\n");
		printf("5.Delete Front 6.Delete Last 7.Delete At Pos 8.ReverseList 9.Search Key\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
				case 1:printf("Enter an integer\n");
						scanf("%d",&ele);
						insertFront(&lobj,ele);
						break;
				case 2:printf("Enter an integer\n");
						scanf("%d",&ele);
						insertLast(&lobj,ele);
						break;
				case 3:printf("Enter an integer\n");
						scanf("%d",&ele);
						printf("Enter the pos\n");
						scanf("%d",&pos);
						insertAtPos(&lobj,ele,pos);
						break;
				case 4: display(&lobj);
						break;
				case 5:if(deleteFront(&lobj,&ele))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
				case 6:if(deleteLast(&lobj,&ele))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
				case 7:	printf("Enter the pos\n");
						scanf("%d",&pos);
						if(deleteAtPos(&lobj,&ele,pos))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
				case 8:printf("Reversed List is\n");
						reverseList(&lobj);
						display(&lobj);
						break;
				case 9:printf("Enter search element\n");
						scanf("%d",&ele);
						pos=searchKey(&lobj,ele);
						if(pos>-1)printf("Found at %d\n",pos);
							else
								printf("Not found\n");
						break;
		}
	}while(choice<10);
	destroyList(&lobj);
	return 0;
}