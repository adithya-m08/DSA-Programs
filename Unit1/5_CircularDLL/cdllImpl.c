#include<stdio.h>
#include<stdlib.h>
#include"cdll.h"

void initList(CDLL* pl)
{
	pl->head=NULL;
}
void insertFront(CDLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	//List Empty
	if(pl->head==NULL)
	{
		temp->prev=temp;
		temp->next=temp;
		pl->head=temp;
		return;
	}
	//One or more nodes
	NODE *last=pl->head->prev;
	
	temp->prev=last;
	temp->next=pl->head;
	last->next=temp;
	pl->head->prev=temp;
	
	pl->head=temp;
}
void insertLast(CDLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	//List Empty
	if(pl->head==NULL)
	{
		temp->prev=temp;
		temp->next=temp;
		pl->head=temp;
		return;
	}
	//One or more nodes
	NODE *last=pl->head->prev;
	temp->prev=last;
	temp->next=pl->head;
	
	last->next=temp;
	pl->head->prev=temp;
}

int countNodes(CDLL *pl)
{
	if(pl->head==NULL)
		return 0;
	NODE *p=pl->head;
	int count=0;
	do
	{
		count++;
		p=p->next;
	}while(p!=pl->head);
	return count;
}
void insertAtPos(CDLL* pl,int ele,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return;
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	if(pos==0)
	{
		insertFront(pl,ele);
		return;
	}
	if(pos==n)
	{
		insertLast(pl,ele);
		return;
	}
	NODE *p=pl->head;
	
	for(int i=0;i<pos;i++)
		p=p->next;
	
	temp->next=p;
	temp->prev=p->prev;
	p->prev->next=temp;
	p->prev=temp;
}
void destroyList(CDLL* pl)
{
	if(pl->head==NULL)
		return;
	
	NODE *last=pl->head->prev;
	while(pl->head!=last)
	{
		pl->head=pl->head->next;
		free(pl->head->prev);
	}
	free(pl->head);
	pl->head=NULL;
}
void display(CDLL* pl)
{
	if(pl->head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	NODE *p=pl->head;
	
	do
	{
		printf("%d ",p->info);
		p=p->next;
	}while(p!=pl->head);
	
	printf("\n");
}
int deleteFront(CDLL* pl,int *pe)
{
	if(pl->head==NULL)
		return 0;
	NODE *last=pl->head->prev;
	//Single Node 
	if(pl->head ==last)
	{
		*pe=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}
	//Multiple nodes
	pl->head->next->prev=last;
	last->next=pl->head->next;
	*pe=pl->head->info;
	free(pl->head);
	pl->head=last->next;
	return 1;
}
int deleteLast(CDLL* pl,int *pe)
{
	if(pl->head==NULL)
		return 0;
	NODE *last=pl->head->prev;
	//Single Node 
	if(pl->head ==last)
	{
		*pe=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}
	//Multiple nodes
	*pe=last->info;
	last->prev->next=pl->head;
	pl->head->prev=last->prev;
	free(last);
	return 1;
}
int deleteAtPos(CDLL* pl,int *pe,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n-1)
		return 0;
/* 	if(pos==0)
		return deleteFront(pl,pe);
	if(pos==n-1)
		return deleteLast(pl,pe);
	 */
	 
	NODE *p=pl->head;
	for(int i=0;i<pos;i++)
		p=p->next;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	if(pos==0)
		pl->head=p->next;
	*pe=p->info;
	free(p);
	return 1;
}