typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* insertFront(NODE*,int);
void display(NODE*);
NODE* destroyList(NODE*);
void insertFront1(NODE**,int);