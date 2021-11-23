#define MAX 5
typedef struct queue
{
	int q[MAX];
	int front,rear;	
}QUEUE;

void initQueue(QUEUE *pq);
//Precondition: Queue is created and initialized
//Precondn: Queue is not full
//Postcondition: ele is successfully enqd
void enqueue(QUEUE *pq,int ele);

//Precondition: Queue is non empty
//Postcondition:deqd ele is successfully returned back
int dequeue(QUEUE *pq);

int isFull(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);