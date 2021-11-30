#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int info;
	struct node *left, *right;
} NODE;
typedef struct tree
{
	NODE *root;
} TREE;

void init(TREE *pt)
{
	pt->root = NULL;
}

NODE *createNode(int ele)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = ele;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//BST: Iterative insert
void insert(TREE *pt, int ele)
{
	NODE *temp = createNode(ele);
	if (pt->root == NULL)
	{
		pt->root = temp;
		return;
	}
	NODE *p = pt->root;
	NODE *q = NULL;

	while (p != NULL)
	{
		q = p;
		if (temp->info < p->info)
			p = p->left;
		else
			p = p->right;
	}
	if (temp->info < q->info)
		q->left = temp;
	else
		q->right = temp;
}

//BST: Recursive Insert
NODE *rinsert(NODE *r, NODE *temp)
{
	if (r == NULL)
		return temp;
	if (temp->info < r->info)
		r->left = rinsert(r->left, temp);
	else
		r->right = rinsert(r->right, temp);

	return r;
}

void recInsert(TREE *pt, int ele)
{
	NODE *temp = createNode(ele);
	pt->root = rinsert(pt->root, temp);
}

void inorder(NODE *r)
{
	if (r != NULL)
	{
		inorder(r->left);
		printf("%d ", r->info);
		inorder(r->right);
	}
}

void preorder(NODE *r)
{
	if (r != NULL)
	{
		printf("%d ", r->info);
		preorder(r->left);
		preorder(r->right);
	}
}

void postorder(NODE *r)
{
	if (r != NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d ", r->info);
	}
}

NODE *delNode(NODE *r, int ele)
{
	NODE *temp = NULL, *p = NULL;
	if (r == NULL)
		return r;
	if (ele < r->info)
		r->left = delNode(r->left, ele);
	else if (ele > r->info)
		r->right = delNode(r->right, ele);
	else if (r->left == NULL)
	{
		temp = r->right;
		free(r);
		return temp;
	}
	else if (r->right == NULL)
	{
		temp = r->left;
		free(r);
		return temp;
	}
	else
	{
		p = r->right;
		while (p->left != NULL)
			p = p->left;
		r->info = p->info;
		r->right = delNode(r->right, p->info);
	}
	return r;
}

//BST: Recursive search
int rsearch(NODE *r, int ele)
{
	if (r == NULL)
		return 0;
	if (ele == r->info)
		return 1;
	if (ele < r->info)
		return rsearch(r->left, ele);
	else
		return rsearch(r->right, ele);
}

//BST: Iterative search
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
//BST: find min ele (Iterative approach)
int min(NODE *r)
{
	while (r->left != NULL)
		r = r->left;
	return r->info;
}

/*
//BST: find min ele (Recursive approach)
int min(NODE* r)
{
	if(r->left == NULL)
		return r->info;
	return min(r->left);
}
*/

/*
//BST: find max ele (Iterative approach)
int max(NODE* r)
{
	while(r->right != NULL)
		r=r->right;
	return r->info;
}
*/

//BST: find max elt (Recursive approach)
int max(NODE *r)
{
	if (r->right == NULL)
		return r->info;
	return max(r->right);
}
int maximum(int a, int b)
{
	return a > b ? a : b;
}
int height(NODE *r)
{
	if (r == NULL)
		return -1;
	return maximum(height(r->left), height(r->right)) + 1;
}
void destroyNode(NODE *r)
{
	if (r != NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		//		printf("\nFreeing %d",r->info);
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

int main()
{
	TREE tobj;
	init(&tobj);
	int choice, ele;
	do
	{
		printf("\n1.Insert 2.Recursiveinsert 3.Inorder 4.Preorder 5.Postorder\n");
		printf("6.DeleteNode 7.Srch 8.MinElt 9.MaxElt 10.Tree height\n");
		printf("11.Tree Depth 12.exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter an element\n");
			scanf("%d", &ele);
			insert(&tobj, ele);
			break;
		case 2:
			printf("enter an element\n");
			scanf("%d", &ele);
			recInsert(&tobj, ele);
			break;
		case 3:
			inorder(tobj.root);
			break;
		case 4:
			preorder(tobj.root);
			break;
		case 5:
			postorder(tobj.root);
			break;
		case 6:
			printf("enter the element to be deleted\n");
			scanf("%d", &ele);
			if (search(tobj.root, ele))
			{
				tobj.root = delNode(tobj.root, ele);
				printf("Inorder Traversal after deletion\n");
				inorder(tobj.root);
			}
			else
				printf("Element not present\n");
			break;
		case 7:
			printf("enter the info to be searched\n");
			scanf("%d", &ele);
			/* recursion is on node object,so passing root node's addr.
				if addr of tree object is passed Eg: rsearch(&tobj,ele)
				then use another recursive helper function
				to recurse through the nodes
				Eg1: see recInsert and rinsert functions
				Eg2: see destroyTree and destroyNode functions
			*/
			if (rsearch(tobj.root, ele))
				printf("%d found\n", ele);
			else
				printf("%d not found\n", ele);
			break;
		case 8:
			if (tobj.root == NULL)
				printf("Tree is empty\n");
			else
				printf("Minimum element = %d\n", min(tobj.root));
			break;
		case 9:
			if (tobj.root == NULL)
				printf("Tree is empty\n");
			else
				printf("Maximum element = %d\n", max(tobj.root));
			break;
		case 10:
			printf("Tree height=%d", height(tobj.root));
			break;
		case 11:
			printf("Tree Depth=%d", height(tobj.root));
			break;
		case 12:
			break;
		}
	} while (choice < 12);
	/*
Here address of tree obj is passed to destroyTree function
so one more recursive helper function is used to
recurse through the nodes in a non empty tree
and delete the nodes in the following order
left child (if it exists), right child (if it exists) and then parent
*/
	destroyTree(&tobj);
}