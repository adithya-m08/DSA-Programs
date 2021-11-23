#include"llist.h"
#include<stdio.h>
#include<stdlib.h>

void initList(NODE** phead)
{
	*phead=NULL;
}

void destroyList(NODE **phead)
{
	NODE *p=*phead;
	while(p!=NULL)
	{
		*phead=p->next;
		free(p);
		p=*phead;
	}
}
int countNodes(NODE *phead)
{
	int count=0;
	if(phead==NULL)
		return count;
	NODE *p=phead;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
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
void insertAtPos(NODE** phead,int ele,int pos,int* status)
{
	int n=countNodes(*phead);
	if(pos<0 || pos>n)
	{
		*status=0;
		return;
	}
	NODE *temp=getNode(ele);
	if(temp==NULL)
	{
		*status=0;
		return;
	}
	//pos = 0
	if(pos==0)
	{
		temp->next=*phead;
		*phead=temp;
		*status=1;
		return;
	}
	
	NODE *p=*phead,*q=NULL;
	
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
	*status=1;
}

void display(NODE* phead)
{
	if(phead==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	NODE *p=phead;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}

void deleteAtPos(NODE** phead,int *pe,int pos,int* status)
{
	int n=countNodes(*phead);
	if(pos<0 || pos>=n)
	{
		*status=0;
		return;
	}
	NODE *p=*phead,*q=NULL;
	if(pos==0)
	{
		*phead=p->next;
		*pe=p->info;
		free(p);
		*status=1;
		return;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	*pe=p->info;
	free(p);
	*status=1;
}