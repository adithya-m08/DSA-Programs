#include"llist.h"
#include<stdio.h>
#include<stdlib.h>

NODE* getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
}

NODE* insertFront(NODE *head,int ele)
{
	NODE* temp=getNode(ele);
	temp->next=head;
	return temp; //or // head=temp; return head;
}

void display(NODE* head)
{
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	NODE* p=head;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
NODE* destroyList(NODE* headp)
{
	NODE *p=headp,*q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	headp=NULL;
//	return headp;
}
void insertFront1(NODE** head,int ele)
{
	NODE* temp=getNode(ele);
	temp->next=*head;
	*head=temp;
}