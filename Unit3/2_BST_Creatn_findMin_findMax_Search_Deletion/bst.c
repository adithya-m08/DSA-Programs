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
	
	int min=findMin(&tobj);
	if(min==-1)
		printf("Empty Tree\n");
	else
		printf("Min=%d\n",min);
	
	int max=findMax(&tobj);
	if(max==-1)
		printf("Empty Tree\n");
	else
		printf("Max=%d\n",max);
	
	int ele;
	printf("Enter the element you want to delete\n");
	scanf("%d",&ele);
	if(searchEle(&tobj,ele))
	{
//		printf("%d found\n",ele);
		deleteNode(&tobj,ele);
		inorder(&tobj);
	}
	else
	{
		printf("%d not found or tree is empty\n",ele);
	}
	
	destroyTree(&tobj);
	return 0;
}