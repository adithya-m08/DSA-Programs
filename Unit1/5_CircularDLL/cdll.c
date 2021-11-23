#include<stdio.h>
#include"cdll.h"

int main()
{
	CDLL lobj;
	initList(&lobj);
	int choice,ele,pos;
	
	do{
		printf("1.Insert Front 2.Insert Last 3.Insert At Pos 4.Display\n");
		printf("5.Delete Front 6.Delete Last 7.Delete At Pos\n");
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
		}
	}while(choice<8);
	destroyList(&lobj);
	return 0;
}