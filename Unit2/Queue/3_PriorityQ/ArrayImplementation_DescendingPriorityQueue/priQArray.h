//Descending priority Queue
#define MAX 5
typedef struct priQ
{
	int info;
	int pri;
}PRIQ;

void insert(PRIQ *pq,int ele,int pty,int *count);
PRIQ maxDelete(PRIQ *pq,int *count);
void display(PRIQ *pq,int *count);

