typedef struct node
{
	int info;
	struct node *left,*right;
}NODE;

typedef struct tree
{
	NODE* root;
}TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);
void destroyTree(TREE *pt);