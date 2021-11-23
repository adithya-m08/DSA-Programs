typedef struct node
{
	int info;
	struct node *prev,*next;
}NODE;

typedef struct dlist
{
	struct node* head;
}DLIST;

void initList(DLIST*);
void destroyList(DLIST*);
void insertFront(DLIST*,int);
void insertLast(DLIST*,int);
int deleteFront(DLIST*,int*);
int deleteLast(DLIST*,int*);
void display(DLIST*);
void insertAfterEle(DLIST*,int,int);
int deleteGivenEle(DLIST*,int,int*);
void insertAtPos(DLIST*,int,int);
int deleteAtPos(DLIST*,int,int*);