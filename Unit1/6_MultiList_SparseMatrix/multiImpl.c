#include"multi.h"
#include<stdio.h>
#include<stdlib.h>
void initList(LIST ** pl)
{
	*pl=NULL;
}

void createList(LIST **pl)
{
	int choice,row=0;
	printf("Row 0 added\n");
	LIST *p=*pl;
	do
	{
		LIST *temp=malloc(sizeof(LIST));
		temp->down=NULL;
		temp->head=NULL;
		temp->tail=NULL;
		
		if(*pl==NULL)
		{
			*pl=temp;
			p=temp;
		}
		else
		{
			p->down=temp;
			p=p->down;
		}
		row++;
		printf("Do you want to add row %d\n",row);
		scanf("%d",&choice);
	}while(choice);
	
	p=*pl;
	row=0;
	while(p!=NULL)
	{
		printf("Do you want to add entries to row %d\n",row);
		scanf("%d",&choice);
		if(choice)
		{
			do
			{
				NODE *temp=malloc(sizeof(NODE));
				printf("Enter col no. and val\n");
				scanf("%d%d",&temp->col,&temp->val);
				temp->next=NULL;
				
				if(p->head==NULL)
				{
					p->head=p->tail=temp;
				}
				else
				{
					p->tail->next=temp;
					p->tail=temp;
				}
				printf("Do you want to add any more entries to row %d\n",row);
				scanf("%d",&choice);
			}while(choice);
		}
		p=p->down;
		row++;
	}
}
void display(LIST **pl)
{
	LIST *p=*pl;
	NODE *q;
	int row=0;
	while(p!=NULL)
	{
		q=p->head;
		while(q!=NULL)
		{
			printf("Row %d,Col %d,Val %d\n",row,q->col,q->val);
			q=q->next;
		}
		p=p->down;
		row++;
	}
}