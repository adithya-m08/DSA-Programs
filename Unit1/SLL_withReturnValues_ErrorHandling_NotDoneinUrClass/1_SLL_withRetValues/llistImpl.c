#include"llist.h"
#include<stdlib.h>
#include<stdio.h>

void initList(LLIST* pl)
{
	pl->head=NULL;
}
void destroyList(LLIST* pl)
{
	NODE *p=pl->head;
	while(pl->head!=NULL)
	{
		pl->head=p->next;
		free(p);
		p=pl->head;
	}
}

NODE* getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	if(temp==NULL)
		return NULL;		//return temp
	
	temp->info=ele;
	temp->next=NULL;
	
	return temp;
}

int insertFront(LLIST* pl,int ele)
{
	NODE* temp=getNode(ele);
	if(temp==NULL)
		return 0;
	temp->next=pl->head;
	pl->head=temp;
	return 1;
}
int insertLast(LLIST* pl,int ele)
{
	NODE* temp=getNode(ele);
	if(temp==NULL)
		return 0;
	//List Empty
	if(pl->head==NULL)
	{
		pl->head=temp;
		return 1;
	}
	NODE* p=pl->head;

	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
	return 1;
}
int countNodes(LLIST *pl)
{
	int count=0;
	if(pl->head==NULL)
		return count;
	NODE *p=pl->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
int insertAtPos(LLIST* pl,int ele,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return 0;
	NODE *temp=getNode(ele);
	if(temp==NULL)
		return 0;
	//pos = 0
	if(pos==0)
	{
		temp->next=pl->head;
		pl->head=temp;
		return 1;
	}
	
	NODE *p=pl->head,*q=NULL;
	
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
	return 1;
}
void display(LLIST* pl)
{
	if(pl->head==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	NODE *p=pl->head;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
int deleteFront(LLIST* pl,int* pe)
{
	if(pl->head==NULL)
		return 0;
	NODE *p=pl->head;
	pl->head=p->next;
	*pe=p->info;
	free(p);
	return 1;
}
int deleteLast(LLIST* pl,int* pe)
{
	if(pl->head==NULL)
		return 0;
	NODE *p=pl->head,*q=NULL;
	//Single Node Case
	if(p->next==NULL)
	{
		pl->head=p->next; //pl->head=NULL
		*pe=p->info;
		free(p);
		return 1;
	}
	//More than one node
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	*pe=p->info;
	free(p);
	q->next=NULL;
	return 1;
}
int deleteAtPos(LLIST* pl,int* pe,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>=n)
		return 0;
	NODE *p=pl->head,*q=NULL;
	if(pos==0)
	{
		pl->head=p->next;
		*pe=p->info;
		free(p);
		return 1;
	}
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

int searchKey(LLIST* pl,int key)
{
	NODE *p=pl->head;
	int pos=0;
	if(pl->head==NULL)
		return -1;
	while(p!=NULL)
	{
		if(p->info==key)
			return pos;
		p=p->next;
		pos++;
	}
	return -1;
}