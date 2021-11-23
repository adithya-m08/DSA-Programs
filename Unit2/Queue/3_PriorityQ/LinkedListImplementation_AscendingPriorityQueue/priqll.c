#include<stdio.h>
#include"priQLL.h"

int main()
{
	PRIQ q;

	initQueue(&q);
	int choice,ele,pri;
	
	printf("1.Insert 2.minDelete 3.Display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter the ele and pri\n");
					scanf("%d%d",&ele,&pri);
					pqInsert(&q,ele,pri);
					break;
			case 2: if(!isEmpty(&q))	
						printf("Deqd %d\n",minDelete(&q));
					else
						printf("Q is already empty\n");
					break;
			
			case 3:display(&q);
					break;
		}
		printf("1.Insert 2.minDelete 3.Display\n");
		scanf("%d",&choice);	
	}while(choice<4);
	destroyQueue(&q);
}