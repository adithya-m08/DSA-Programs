#define MAX 20
typedef struct node
{
	int info;
	int used;
}NODE;

void initTree(NODE bst[MAX]);
void createTree(NODE bst[MAX]);
void levelorder(NODE bst[MAX]);
void inorder(NODE bst[MAX],int);
void preorder(NODE bst[MAX],int);
void postorder(NODE bst[MAX],int);