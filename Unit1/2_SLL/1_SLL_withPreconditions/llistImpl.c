#include<stdlib.h>
#include"llist.h"
#include<stdio.h>

void initList(LLIST* pl)
{
	pl->head=NULL;
}
NODE* getNode(int ele)
{
	NODE* temp=malloc(sizeof(NODE));
	if(temp!=NULL)
	{
	temp->info=ele;
	temp->next=NULL;}
	return temp;
}
void insertFront(LLIST* pl,int ele)
{
	NODE *temp=getNode(ele);
	temp->next=pl->head;
	pl->head=temp;
}
void insertLast(LLIST* pl,int ele)
{
	NODE *temp=getNode(ele);
//Empty List
	if(pl->head==NULL)
	{
		pl->head=temp;
		return;
	}
	NODE *p=pl->head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
/* 
int countNodes(LLIST *pl)
{
	NODE *p=pl->head;
	int count=0;
	
	if(pl->head==NULL)
		return count;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
 */
//Precondition: pos is a valid position, 0<=pos<=n
//where n is the no. of nodes in the list
void insertAtPos(LLIST* pl,int ele,int pos)
{
//	int n=countNodes(pl);
	NODE *temp=getNode(ele);
//	if(pos<0 || pos>n) return;
	if(pos==0)
	{
		temp->next=pl->head;
		pl->head=temp;
		return;
	}
	NODE *p=pl->head,*q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void display(LLIST* pl)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}

void destroyList(LLIST* pl)
{
	NODE *p=pl->head,*q=NULL;
	while(p!=NULL)
	{
		q=p;		//printf("%d ",p->info);
		p=p->next;
		free(q);
	}
	pl->head=NULL;
}
//Precondition: List exists and is non empty
void deleteFront(LLIST *pl,int *pe)
{
//	if(pl->head==NULL) return;
	NODE *p=pl->head;
	pl->head=p->next;
	*pe=p->info;
	free(p);
}
//Precondition: List exists and is non empty
void deleteLast(LLIST *pl,int *pe)
{
//		if(pl->head==NULL) return;
	NODE *p=pl->head;
	//Single Node
	if(p->next==NULL)
	{
		*pe=p->info;
		pl->head=NULL;
		free(p);
		return;
	}
	NODE *q=NULL;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	*pe=p->info;
	q->next=NULL;
	free(p);
}
//Precondition: List exists and is non empty
//pos is a valid position, 0<=pos<n
//where n is the no. of nodes in the list
void deleteAtPos(LLIST *pl,int *pe,int pos)
{
	NODE *p=pl->head;
	if(pos==0)
	{
		pl->head=p->next;
		*pe=p->info;
		free(p);
		return;
	}
	NODE *q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	*pe=p->info;
	free(p);
}
void reverseList(LLIST *pl)
{
	NODE *prev=NULL,*cur=pl->head,*next=NULL;
	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	pl->head=prev;
}
int searchKey(LLIST *pl,int ele)
{
	NODE *p=pl->head;
	int pos=0;
	while(p!=NULL)
	{
		if(p->info==ele)
		{	
			return pos;
		}
		pos++;
		p=p->next;
	}
	return -1;
}