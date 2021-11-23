typedef struct node
{
	int col;
	int val;
	struct node *next;
}NODE;

typedef struct list
{
	struct list *down;
	NODE *head,*tail;	
}LIST;

void initList(LIST **);
void createList(LIST **);
void display(LIST **);