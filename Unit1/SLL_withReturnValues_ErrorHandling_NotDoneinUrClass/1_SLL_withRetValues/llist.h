typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE* head;
}LLIST;

void initList(LLIST*);
void destroyList(LLIST*);
int insertFront(LLIST*,int);
int insertLast(LLIST*,int);
int insertAtPos(LLIST*,int,int);
void display(LLIST*);
int deleteFront(LLIST*,int*);
int deleteLast(LLIST*,int*);
int deleteAtPos(LLIST*,int*,int);
int searchKey(LLIST*,int);