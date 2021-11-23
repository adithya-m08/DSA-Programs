#define MAX 50
typedef struct node
{
	 char info;
	 struct node *left,*right;
}NODE;
typedef struct tree
{
	NODE *root;
}TREE;
typedef struct stack
{
	int top;
	NODE *s[MAX];
}STACK;
void initTree(TREE *pt);
void createTree(TREE *pt,char expr[MAX]);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);
int evalExprTree(TREE *pt);
void destroyTree(TREE *pt);
void initStack(STACK *ps);
void push(STACK *ps,NODE* ele);
NODE* pop(STACK *ps);