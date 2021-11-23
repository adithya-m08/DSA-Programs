#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left,*right;
	int rthread;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;

void initTree(TREE *pt)
{
	pt->root=NULL;
}
void setLeft(NODE *q,NODE *temp)
{
	q->left=temp;
	temp->right=q;
}

void setRight(NODE *p,NODE *temp)
{
	temp->right=p->right;
	p->right=temp;
	p->rthread=0;
}

NODE* createNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->left=temp->right=NULL;
	temp->rthread=1;
	
	return temp;
}
void createTree(TREE *pt)
{
	int ele,choice;
	printf("Enter root info\n");
	scanf("%d",&ele);
	pt->root=createNode(ele);
	
	printf("Do you want to add another node\n");
	scanf("%d",&choice);
	
	NODE *p,*q,*temp;
	while(choice)
	{
		p=pt->root;
		q=NULL;
		printf("Enter node info\n");
		scanf("%d",&ele);
		
		temp=createNode(ele);
		
		while(p!=NULL)
		{
			q=p;
			if(temp->info<p->info)
				p=p->left;
			else
			{
				if(p->rthread)
					break;
				p=p->right;
			}
		}
		if(p==NULL)
			setLeft(q,temp);
		else
			setRight(p,temp);
		printf("Do you want to add one more node\n");
		scanf("%d",&choice);
	}
}

void inorder(TREE *pt)
{
	NODE *p=pt->root;
	NODE *q=NULL;
	do
	{
		q=NULL;
		while(p!=NULL)
		{
			q=p;
			p=p->left;
		}
		if(q!=NULL)
		{
			printf("%d ",q->info);
			p=q->right;
			while(q->rthread && p!=NULL)
			{
				printf("%d ",p->info);
				q=p;
				p=p->right;
			}
		}
	}while(q!=NULL);
}

int main()
{
	TREE tobj;
	initTree(&tobj);
	createTree(&tobj);
	inorder(&tobj);
}