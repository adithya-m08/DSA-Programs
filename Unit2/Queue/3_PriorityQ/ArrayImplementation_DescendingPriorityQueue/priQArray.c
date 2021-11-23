#include"priQArray.h"
#include<stdio.h>

int main()
{
	PRIQ pq[MAX];
	
	int choice,ele,pri,count=0;
	PRIQ temp;
	printf("1.Enq 2.MaxDelete 3.Display\n");
	scanf("%d",&choice);
	do{
	
	switch(choice)
	{
		case 1:if(count!=MAX)
				{
				printf("Enter ele & pri\n");
				scanf("%d%d",&ele,&pri);
				insert(pq,ele,pri,&count);
				}
				else
					printf("Queue is already full\n");
				break;
		case 2:if(count)
				{
					temp=maxDelete(pq,&count);
					printf("Data:%d Pri:%d",temp.info,temp.pri);
				}
				else
					printf("Queue is already empty\n");
				break;
		case 3:display(pq,&count);
				break;
	}
	printf("\n1.Enq 2.MaxDelete 3.Display\n");
	scanf("%d",&choice);
	}while(choice<4);
}
