#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void initTree(TREE *pt)
{
	pt->root = NULL;
}

void createTree(TREE *pt)
{
	int choice;
	NODE *temp = malloc(sizeof(NODE));
	temp->left = temp->right = NULL;

	printf("Enter the info\n");
	scanf("%d", &temp->info);

	pt->root = temp;

	printf("Do you want to add one more node\n");
	scanf("%d", &choice);
	while (choice)
	{
		temp = malloc(sizeof(NODE));
		temp->left = temp->right = NULL;

		printf("Enter the info\n");
		scanf("%d", &temp->info);

		NODE *p = pt->root;
		NODE *q = NULL;
		while (p != NULL)
		{
			if (temp->info <= p->info)
			{
				q = p;
				p = p->left;
			}
			else
			{
				q = p;
				p = p->right;
			}
		}
		if (temp->info <= q->info)
			q->left = temp;
		else
			q->right = temp;
		printf("Do you want to add one more node\n");
		scanf("%d", &choice);
	}
}
void inord(NODE *r)
{
	if (r == NULL)
		return;
	inord(r->left);
	printf("%d ", r->info);
	inord(r->right);
}
void inorder(TREE *pt)
{
	inord(pt->root);
}
void preord(NODE *r)
{
	if (r != NULL)
	{
		printf("%d ", r->info);
		preord(r->left);
		preord(r->right);
	}
}
void preorder(TREE *pt)
{
	preord(pt->root);
}
void postord(NODE *r)
{
	if (r != NULL)
	{
		postord(r->left);
		postord(r->right);
		printf("%d ", r->info);
	}
}
void postorder(TREE *pt)
{
	postord(pt->root);
}
void destroyNode(NODE *r)
{
	if (r != NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		printf("\nFreeing%d", r->info);
		free(r);
	}
}
void destroyTree(TREE *pt)
{
	if (pt->root != NULL)
	{
		destroyNode(pt->root);
		pt->root = NULL;
	}
}
int findMinimum(NODE *r)
{
	if (r == NULL)
		return -1;

	while (r->left != NULL)
		r = r->left;

	return r->info;
}
int findMin(TREE *pt)
{
	return findMinimum(pt->root);
}
int findMaximum(NODE *r)
{
	if (r == NULL)
		return -1;

	while (r->right != NULL)
		r = r->right;

	return r->info;
}
int findMax(TREE *pt)
{
	return findMaximum(pt->root);
}

NODE *delNode(NODE *r, int ele)
{
	if (r == NULL)
		return r;

	NODE *temp = NULL;
	if (ele < r->info)
		r->left = delNode(r->left, ele);
	else if (ele > r->info)
		r->right = delNode(r->right, ele);
	else if (r->left == NULL) //single right child case and leaf node case
	{
		temp = r->right;
		free(r);
		return temp;
	}
	else if (r->right == NULL) //single left child case
	{
		temp = r->left;
		free(r);
		return temp;
	}
	else //replacing with inorder successor
	{
		temp = r->right;
		while (temp->left != NULL)
			temp = temp->left;
		r->info = temp->info;
		r->right = delNode(r->right, temp->info);
	}
	/*
//Replacing with inorder predecessor
	else
	{
		temp=r->left;
		while(temp->right!=NULL)
			temp=temp->right;
		r->info=temp->info;
		r->left=delNode(r->left,temp->info);
	}

*/
	return r;
}

/*
//Few students logic, look for change in 2 children case
NODE* delNode(NODE *r,int ele)
{
	NODE *temp=NULL,*prev=NULL;
	if(r==NULL)
		return r;
	
	if(ele<r->info)
		r->left=delNode(r->left,ele);
	else if(ele>r->info)
		r->right=delNode(r->right,ele);
	else if(r->left==NULL) //Single right child & Leaf node
	{
		temp=r->right;
		free(r);
		return temp;
	}
	else if(r->right==NULL)//Single left child
	{
		temp=r->left;
		free(r);
		return temp;
	}
	else	//Two children
	{
		temp=r->right;
		
		while(temp->left!=NULL)
		{
			prev=temp;
			temp=temp->left;
		}
		
		r->info=temp->info;
		if(prev==NULL)
		{
			r->right=temp->right;
			free(temp);
		}
		else
		{			
			prev->left=temp->right;
			free(prev->left);
		}
	}
	return r;	
} 
*/
void deleteNode(TREE *pt, int ele)
{
	pt->root = delNode(pt->root, ele);
}
/* 
int search(NODE *r,int ele)
{
	if(r!=NULL)
	{
		if(ele==r->info)
			return 1;
		else if(ele<r->info)
			return search(r->left,ele);
		else
			return search(r->right,ele);
	}
	return 0;
}
 */
int search(NODE *r, int ele)
{
	while (r != NULL)
	{
		if (ele == r->info)
			return 1;
		else if (ele < r->info)
			r = r->left;
		else
			r = r->right;
	}
	return 0;
}

int searchEle(TREE *pt, int ele)
{
	return search(pt->root, ele);
}