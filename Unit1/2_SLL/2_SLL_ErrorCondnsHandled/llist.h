typedef struct node
{
	int info;
	struct node*next;
}NODE;

typedef struct llist
{
	NODE* head;
}LLIST;

void initList(LLIST*);
void insertFront(LLIST*,int);
void insertLast(LLIST*,int);
void insertAtPos(LLIST*,int,int);
void display(LLIST*);
void destroyList(LLIST*);
int deleteFront(LLIST *,int*);
int deleteLast(LLIST *,int *);
int deleteAtPos(LLIST *,int *,int);
void reverseList(LLIST *);
int searchKey(LLIST *,int);
