typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initList(NODE**);
void destroyList(NODE**);
void insertAtPos(NODE**,int ele,int pos,int* status);
void display(NODE*);
void deleteAtPos(NODE**,int *pe,int pos,int* status);

//10->20->30