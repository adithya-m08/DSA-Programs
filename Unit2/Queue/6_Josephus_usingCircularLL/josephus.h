//Josephus problem using circular linked list
typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE* head,*tail;
}LIST;

void initQueue(LIST*pq);
void createQueue(LIST*pq);
void display(LIST*pq);
int winner(LIST*pq,int start,int skip);