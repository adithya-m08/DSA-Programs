#include<stdio.h>
#include<stdlib.h>
#include"cll.h"

void initList(CLL* pl)
{
	pl->last=NULL;
}

void insertFront(CLL* pl,int ele)
{
	NODE* temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->last==NULL)
	{
		temp->next=temp;
		pl->last=temp;
		return;
	}
	temp->next=pl->last->next;
	pl->last->next=temp;
}
void insertLast(CLL* pl,int ele)
{
	NODE* temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->last==NULL)
	{
		temp->next=temp;
		pl->last=temp;
		return;
	}
	temp->next=pl->last->next;
	pl->last->next=temp;
	pl->last=temp;
}
int countNodes(CLL *pl)
{
	int count=0;
	if(pl->last==NULL)
		return count;
	
	NODE *p=pl->last->next;
	do{
		count++;
		p=p->next;
	}while(p!=pl->last->next);
	return count;
	
	/*
	while(p!=pl->last)
	{
		count++;
		p=p->next;
	}
	count++;
	return count;
	*/
}
void insertAtPos(CLL* pl,int ele,int pos)
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
	NODE *p=pl->last->next,*q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void destroyList(CLL* pl)
{
	if(pl->last==NULL)
		return;
	NODE *p=pl->last->next;
	
	while(p!=pl->last)
	{
		pl->last->next=p->next; //printf("%d ",p->info);
		free(p);
		p=pl->last->next;
	}
//	printf("%d ",p->info);
	free(p);
	pl->last=NULL;
}
void display(CLL* pl)
{
	if(pl->last==NULL)
	{
		printf("Empty List\n");
		return;
	}
	
	NODE *p=pl->last->next;
	do{
		printf("%d ",p->info);
		p=p->next;
	}while(p!=pl->last->next);
	printf("\n");
	/*
	while(p!=pl->last)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("%d\n",p->info);
	*/	
}
int deleteFront(CLL* pl,int *pe)
{
	if(pl->last==NULL)
		return 0;
	
	NODE *p=pl->last->next;
	if(p==pl->last)
	{
		*pe=p->info;
		free(p);
		pl->last=NULL;
		return 1;
	}
	pl->last->next=p->next;
	*pe=p->info;
	free(p);
	return 1;
}
int deleteLast(CLL* pl,int *pe)
{
	if(pl->last==NULL)
		return 0;
	//Single node case
	NODE *p=pl->last->next;
	if(p==pl->last)
	{
		*pe=p->info;
		free(p);
		pl->last=NULL;
		return 1;
	}
	//Multiple Nodes
	while(p->next!=pl->last)
		p=p->next;
	p->next=pl->last->next;
	*pe=pl->last->info;
	free(pl->last);
	pl->last=p;
	return 1;
}
int deleteAtPos(CLL* pl,int *pe,int pos)
{
	if(pl->last==NULL)
		return 0;
	int n=countNodes(pl);
	if(pos<0 || pos>=n)
		return 0;
	
	NODE *p=pl->last->next,*q=NULL;
	if(pos==0)
		return deleteFront(pl,pe);
	if(pos==n-1)
		return deleteLast(pl,pe);
	
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	*pe=p->info;
	free(p);
	return 1;
}