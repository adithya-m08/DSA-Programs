//Stack: Array Implementation, Statically created array
#define MAX 5
typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int push(STACK *ps,int ele);
int isEmpty(STACK *ps);
int stackTop(STACK *ps,int *pe);
int pop(STACK *ps,int *pe);
void display(STACK *ps);