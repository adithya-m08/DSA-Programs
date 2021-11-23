typedef struct node
{
	int info;
	struct node *prev,*next;
}NODE;

typedef struct deque
{
	NODE *front,*rear;
}DEQUE;

void initQueue(DEQUE* pq);
void insertFront(DEQUE* pq,int ele);
void insertLast(DEQUE* pq,int ele);
int isEmpty(DEQUE*pq);
int deleteFront(DEQUE* pq);
int deleteLast(DEQUE* pq);
void display(DEQUE* pq);
void destroyQueue(DEQUE* pq);