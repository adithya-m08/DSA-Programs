#include"llist.h"
#include<stdio.h>
#include<stdlib.h>

void initList(DLIST* pdl)
{
	pdl->head=NULL;
}
void destroyList(DLIST* pdl)
{
	NODE* p=pdl->head;
	if(pdl->head==NULL)
		return;
	while(p->next!=NULL)
	{
		p=p->next;
		free(p->prev);
	}
	free(p);
}
NODE* getNode(int ele)
{
	NODE* temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
void insertFront(DLIST* pdl,int ele)
{
	NODE *temp=getNode(ele);
	if(temp==NULL)
		return;
	temp->next=pdl->head;
	if(pdl->head!=NULL)
		pdl->head->prev=temp;
	pdl->head=temp;
}
void insertLast(DLIST* pdl,int ele)
{
	NODE* temp=getNode(ele);
	if(temp==NULL)
		return;
	NODE*p =pdl->head;
	//Empty case
	if(p==NULL)
	{
		pdl->head=temp;
		return;
	}
	//One or more nodes
	while(p->next!=NULL)
		p=p->next;
	temp->prev=p;
	p->next=temp;
}
int deleteFront(DLIST* pdl,int* pe)
{
	if(pdl->head==NULL)
		return 0;
	NODE *p=pdl->head;
	pdl->head=pdl->head->next;
	if(pdl->head!=NULL)
		pdl->head->prev=NULL;
	
	*pe=p->info;
	free(p);
	return 1;
}
int deleteLast(DLIST *pdl,int* pe)
{
	if(pdl->head==NULL)
		return 0;
	NODE *p=pdl->head;
	//Single Node case
	if(pdl->head->next==NULL)
	{
		pdl->head=NULL;
		*pe=p->info;
		free(p);
		return 1;
	}
	//Multiple Node case
	while(p->next!=NULL)
		p=p->next;
	p->prev->next=NULL;
	*pe=p->info;
	free(p);
	return 1;
}
void display(DLIST* pdl)
{
	NODE *p=pdl->head;
	if(p==NULL)
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
void insertAfterEle(DLIST* pdl,int gi,int ele)
{
	NODE *p=pdl->head;
	while(p!=NULL && p->info!=gi)
		p=p->next;
	if(p==NULL)
		return;
	NODE *temp=getNode(ele);
	
	temp->prev=p;
	temp->next=p->next;
	
	if(p->next!=NULL)
		p->next->prev=temp;
	
	p->next=temp;
	
}
int deleteGivenEle(DLIST* pdl,int ele,int *pos)
{
	int count=0;
	if(pdl->head==NULL)
		return 0;
	NODE* p=pdl->head;
	if(p->info==ele)
	{
		pdl->head=p->next;
		if(pdl->head!=NULL)
			pdl->head->prev=NULL;
		*pos=0;
		free(p);
		return 1;
	}
	while(p!=NULL && p->info!=ele)
	{
		count++;
		p=p->next;
	}
	if(p==NULL)
		return 0;
	p->prev->next=p->next;
	if(p->next!=NULL)
		p->next->prev=p->prev;
	*pos=count;
	free(p);
	return 1;
}
int countNodes(DLIST *pdl)
{
	int count=0;
	if(pdl->head==NULL)
		return count;
	NODE *p=pdl->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void insertAtPos(DLIST* pdl,int ele,int pos)
{
	int n=countNodes(pdl);
	if(pos<0 || pos>n)
		return;
	if(pos==0)
	{
		insertFront(pdl,ele);
		return;
	}
	if(pos==n)
	{
		insertLast(pdl,ele);
		return;
	}
	NODE *temp=getNode(ele);
	NODE *p=pdl->head;
	for(int i=0;i<pos;i++)
		p=p->next;
	temp->prev=p->prev;
	temp->next=p;
	p->prev->next=temp;
	p->prev=temp;
}
int deleteAtPos(DLIST* pdl,int pos,int *pe)
{
	if(pdl->head==NULL)
		return 0;
	int n=countNodes(pdl);
	if(pos<0 || pos>=n)
		return 0;
	if(pos==0)
	{
		if(deleteFront(pdl,pe))
			return 1;
		return 0;
	}
	if(pos==n-1)
	{
		int res=deleteLast(pdl,pe);
			return res;
	}
	NODE* p=pdl->head;
	for(int i=0;i<pos;i++)
		p=p->next;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	*pe=p->info;
	free(p);
	return 1;
	
}