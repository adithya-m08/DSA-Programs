#include<stdio.h>
#include"llist.h"
#include<stdlib.h>

NODE* getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
}

NODE* ordIns(NODE* phead,int ele)
{
	NODE *p=phead,*q=NULL;
	NODE* temp=getNode(ele);
	
	while(p!=NULL && temp->info > p->info)
	{ 
		q=p;
		p=p->next;
	} 

	if(q==NULL)			//if(p==phead)
	{
		temp->next=phead;
		phead=temp; 		
		return phead;
	}
	
	q->next=temp;
	temp->next=p;
	return phead;
}

void display(NODE* phead)
{
	if(phead==NULL)
	{
		printf("Empty List\n");
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
NODE* destroyList(NODE* phead)
{
	NODE *p=phead,*q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	phead=NULL;
	return phead;
}
//Precondition: List is not empty
NODE* deleteFront(NODE* headp,int* pe)
{
	NODE *p=headp;
	headp=p->next;
	*pe=p->info;
	free(p);
	return headp;
}

int searchKey(NODE* phead,int ele)
{
	NODE* p=phead;
	int pos=0;
	while(p!=NULL)
	{
		if(p->info==ele)
		{
			return pos;
		}
		p=p->next;
		pos++;
	}
	return -1;
}