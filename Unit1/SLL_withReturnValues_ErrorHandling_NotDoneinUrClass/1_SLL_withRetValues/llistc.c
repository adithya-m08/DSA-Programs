#include<stdio.h>
#include"llist.h"

int main()
{
	LLIST lobj;
	initList(&lobj);
	
	int choice,ele,pos;
	
	do{
		printf("1.Insert Front 2.Insert Last 3.Display\n");
		printf("4.Delete Front 5. DeleteLast 6.Delete at Pos 7.Insert At Pos 8.Search\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an Integer\n");
					scanf("%d",&ele);
				if(insertFront(&lobj,ele))
					printf("Inserted %d successfuuly\n",ele);
				else
					printf("Insertion failed\n");
				break;
			case 2:printf("Enter an Integer\n");
					scanf("%d",&ele);
				if(insertLast(&lobj,ele))
					printf("Inserted %d successfuuly\n",ele);
				else
					printf("Insertion failed\n");
				break;
			case 3:display(&lobj);
				break;
			case 4:if(deleteFront(&lobj,&ele))
						printf("DEleted ele is %d\n",ele);
					else
						printf("Deletion Failed\n");
					break;
			case 5:if(deleteLast(&lobj,&ele))
						printf("DEleted ele is %d\n",ele);
					else
						printf("Deletion Failed\n");
					break;
			case 6:printf("Enter the pos\n");
					scanf("%d",&pos);
					if(deleteAtPos(&lobj,&ele,pos))
						printf("DEleted ele is %d\n",ele);
					else
						printf("Deletion Failed\n");
					break;
			case 7:printf("Enter the element\n");
					scanf("%d",&ele);
					printf("Enter the pos\n");
					scanf("%d",&pos);
					if(insertAtPos(&lobj,ele,pos))
						printf("Inserted %d successfuuly\n",ele);
					else
						printf("Insertion failed\n");
					break;
			case 8:printf("Enter the element to be searched\n");
					scanf("%d",&ele);
					pos=searchKey(&lobj,ele);
					if(pos==-1)
						printf("Element not found\n");
					else
						printf("Found at pos %d\n",pos);
					break;
		}
	}while(choice<9);
	destroyList(&lobj);
}