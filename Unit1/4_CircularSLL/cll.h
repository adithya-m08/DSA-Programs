typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct cll
{
	NODE* last;
}CLL;

void initList(CLL* pl);
void insertFront(CLL* pl,int ele);
void insertLast(CLL* pl,int ele);
void insertAtPos(CLL* pl,int ele,int pos);
void destroyList(CLL* pl);
void display(CLL* pl);
int deleteFront(CLL* pl,int *pe);
int deleteLast(CLL* pl,int *pe);
int deleteAtPos(CLL* pl,int *pe,int pos);