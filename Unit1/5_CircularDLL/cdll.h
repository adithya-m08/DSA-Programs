typedef struct node
{
	int info;
	struct node *prev,*next;
}NODE;

typedef struct list
{
	NODE *head;
}CDLL;

void initList(CDLL* pl);
void insertFront(CDLL* pl,int ele);
void insertLast(CDLL* pl,int ele);
void insertAtPos(CDLL* pl,int ele,int pos);
void destroyList(CDLL* pl);
void display(CDLL* pl);
int deleteFront(CDLL* pl,int *pe);
int deleteLast(CDLL* pl,int *pe);
int deleteAtPos(CDLL* pl,int *pe,int pos);