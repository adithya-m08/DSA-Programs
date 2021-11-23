typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* ordIns(NODE*,int);
NODE* deleteFront(NODE*,int*);
NODE* destroyList(NODE*);
void display(NODE*);
int searchKey(NODE*,int);