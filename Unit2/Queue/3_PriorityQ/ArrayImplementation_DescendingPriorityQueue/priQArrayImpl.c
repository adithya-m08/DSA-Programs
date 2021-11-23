#include"priQArray.h"
#include<stdio.h>

//Ordered insertion
void insert(PRIQ *pq,int ele,int pty,int *count)
{
	int i=*count-1;
	
	PRIQ key;
	key.info=ele;
	key.pri=pty;
		
	while(i>=0 && key.pri>pq[i].pri)
	{
		pq[i+1]=pq[i];
		i--;
	}
	pq[i+1]=key;
	(*count)++;
}
PRIQ maxDelete(PRIQ *pq,int *count)
{
	PRIQ key=pq[0];
	
	for(int i=1;i<*count;i++)
		pq[i-1]=pq[i];
	(*count)--;
	
	return key;
}
void display(PRIQ *pq,int *count)
{
	if(*count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	for(int i=0;i<*count;i++)
		printf("Data:%d Pri:%d|",pq[i].info,pq[i].pri);
}