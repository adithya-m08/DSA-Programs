typedef struct node
{
	int info;
	int pri;
	struct node *next;
}NODE;

typedef struct priqueue
{
	NODE *head;
}PRIQ;

void initQueue(PRIQ*);
void pqInsert(PRIQ*,int ele,int pri);
int isEmpty(PRIQ*);
int minDelete(PRIQ*);
void display(PRIQ*);
void destroyQueue(PRIQ*);
