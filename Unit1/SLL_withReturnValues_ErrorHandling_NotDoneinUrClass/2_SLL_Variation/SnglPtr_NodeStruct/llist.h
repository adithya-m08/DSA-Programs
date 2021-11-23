typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE*);
NODE* destroyList(NODE*);
NODE* insertAtPos(NODE*,int ele,int pos,int* status);
void display(NODE*);
NODE* deleteAtPos(NODE*,int *pe,int pos,int* status);

//10->20->30