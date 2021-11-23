#include<stdio.h>
#include"llist.h"

int main()
{
	NODE* head=NULL;
	int choice,ele,pos;
	do{
		printf("1.Ordered Ins 2. DelFrnt 3. Display 4:search\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an ele\n");;
					scanf("%d",&ele);
					head=ordIns(head,ele);
					break;
			case 2:head=deleteFront(head,&ele);
					printf("Deleted ele is %d\n",ele);
					break;
			case 3:display(head);
					break;
			case 4: printf("Enter an ele\n");;
					scanf("%d",&ele);
					pos=searchKey(head,ele);
					if(pos>-1)
						printf("Elemenet found at pos %d\n",pos);
					else
						printf("Ele not found\n");
					break;
		}
	}while(choice<5);
	head=destroyList(head);
}