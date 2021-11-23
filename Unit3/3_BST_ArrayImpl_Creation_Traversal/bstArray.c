#include<stdio.h>
#include"bstArray.h"

int main()
{
	NODE bst[MAX];
	
	initTree(bst);
	createTree(bst);
	
	printf("Tree in Level order Traversal\n");
	levelorder(bst);
	
	printf("\nInorder Traversal\n");
	inorder(bst,0);

	printf("\nPreorder Traversal\n");
	preorder(bst,0);
	
	printf("\nPostorder Traversal\n");
	postorder(bst,0);
}