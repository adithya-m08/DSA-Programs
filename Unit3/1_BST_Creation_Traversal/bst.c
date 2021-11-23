#include"bst.h"
#include<stdio.h>

int main()
{
	TREE tobj;
	
	initTree(&tobj);	//tobj.root=NULL;
	createTree(&tobj);
	
	printf("Inorder Traversal\n");
	inorder(&tobj);
	
	printf("\nPreorder Traversal\n");
	preorder(&tobj);

	printf("\nPostorder Traversal\n");
	postorder(&tobj);
	
	destroyTree(&tobj);
	return 0;
}