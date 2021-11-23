#include<stdio.h>
#include"llist.h"

int main()
{
	DLIST lobj;
	initList(&lobj);
	int choice,ele,pos,givenEle,res;
	
	do{
		printf("1.Insert Front 2.Insert Last 3.Display\n");
		printf("4.Delete Front 5. Delete Lst 6.InsertAfterEle\n");
		printf("7.DeleteGivenEle 8.InsertAtPos 9.DeleteAtPos\n");
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
				 case 4: if(deleteFront(&lobj,&ele))
							printf("deleted ele is %d\n",ele);
						else
							printf("Empty List\n");
						break;
				case 5: if(deleteLast(&lobj,&ele))
							printf("deleted ele is %d\n",ele);
						else
							printf("Empty List\n");
						break; 
				case 3:display(&lobj);
						break;
				case 6:printf("Enter the ele after which you want to insert\n");
						scanf("%d",&givenEle);
						printf("Enter the ele\n");
						scanf("%d",&ele);
						insertAfterEle(&lobj,givenEle,ele);
						break;
				case 7:printf("Enter the ele you want to del\n");
						scanf("%d",&ele);
						res=deleteGivenEle(&lobj,ele,&pos);
						if(res==0)
							printf("Deletion failed\n");
						else
							printf("Element deleted at pos %d\n",pos);
				case 8:printf("Enter the ele\n");
						scanf("%d",&ele);
						printf("Enter the pos\n");
						scanf("%d",&pos);
						insertAtPos(&lobj,ele,pos);
						break;
				case 9:printf("Enter the pos\n");
						scanf("%d",&pos);
						if(deleteAtPos(&lobj,pos,&ele))
							printf("DEleted ele is %d\n",ele);
						else
							printf("DEl failed\n");
						break;
		}
	}while(choice<10);
	destroyList(&lobj);
	return 0;
}