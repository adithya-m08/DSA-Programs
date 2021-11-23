//Open Hashing
//Hash function: rNo%tableSize
//Collision Resolution: Open hashing/Separate Chaining
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7

typedef struct element
{
	int rNo;
	char name[30];
	struct element *next;
}NODE;

void initTable(NODE* ht[SIZE]);
void insert(NODE* ht[SIZE],int rNo,char name[30]);
int delete(NODE* ht[SIZE],int rNo);
int search(NODE* ht[SIZE],int rNo,char name[30]);
void display(NODE *ht[SIZE]);
void destroyTable(NODE* ht[SIZE]);

int main()
{
	NODE *ht[SIZE]; //create hashtable
	initTable(ht);	//initialize hashtable
	
	int choice,rNo;
	char name[30];
	printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
	scanf("%d",&choice);
	do{
		switch(choice)
		{
			case 1: printf("Enter the rNo\n");
					scanf("%d",&rNo);
					printf("Enter the name\n");
					scanf("%s",name);
					insert(ht,rNo,name);
					break;
			case 2: printf("Enter the rNo\n");
					scanf("%d",&rNo);
					if(delete(ht,rNo))
						printf("Record with rNo %d deleted\n",rNo);
					else
						printf("Record not found\n");
					break;
			case 3: printf("Enter the rNo\n");
					scanf("%d",&rNo);
					
					if(search(ht,rNo,name))
						printf("Rcrdfound:RollNo:%d,Name:%s\n",rNo,name);
					else
						printf("Record not found\n");
					break;
			case 4: display(ht);
					break;
			case 5: destroyTable(ht);
					return 0;
		}
		printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
		scanf("%d",&choice);
	}while(choice<6);
	destroyTable(ht);
}

void initTable(NODE* ht[SIZE])
{
	for(int i=0;i<SIZE;i++)
		ht[i]=NULL;
}

void insert(NODE* ht[SIZE],int rNo,char name[30])
{
	int index=rNo%SIZE;
	NODE* temp=malloc(sizeof(NODE));
	temp->rNo=rNo;
	strcpy(temp->name,name);
	temp->next=NULL;
	
	if(ht[index]==NULL)
	{
		ht[index]=temp;
		return;
	}
	
	NODE *cur=ht[index];
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=temp;
}

int delete(NODE* ht[SIZE],int rNo)
{
	int index=rNo%SIZE;
	
	NODE *cur=ht[index];
	NODE *prev=NULL;
	
	while(cur!=NULL && cur->rNo!=rNo)
	{
		prev=cur;
		cur=cur->next;		
	}
	if(cur!=NULL)
	{
		if(prev==NULL)
			ht[index]=cur->next;
		else
			prev->next=cur->next;
		free(cur);
		return 1;
	}
	return 0;
}
int search(NODE* ht[SIZE],int rNo,char name[30])
{
	int index=rNo%SIZE;
	
	NODE *cur=ht[index];
	
	while(cur!=NULL)
	{
		if(cur->rNo==rNo)
		{
			strcpy(name,cur->name);
			return 1;
		}
		cur=cur->next;
	}
	return 0;
}
void display(NODE *ht[SIZE])
{
	NODE *cur;
	for(int i=0;i<SIZE;i++)
	{
		cur=ht[i];
		printf("h[%d]->",i);
		while(cur!=NULL)
		{
			printf("%d %s-> ",cur->rNo,cur->name);
			cur=cur->next;
		}
		printf("NULL\n");
	}
}
void destroyTable(NODE* ht[SIZE])
{
	NODE *cur,*prev;
	for(int i=0;i<SIZE;i++)
	{
		cur=ht[i];
		while(cur!=NULL)
		{
			prev=cur;
			cur=cur->next;
//			printf("Freeing %d\n",prev->rNo);
			free(prev);
		}
		ht[i]=NULL;
	}
}