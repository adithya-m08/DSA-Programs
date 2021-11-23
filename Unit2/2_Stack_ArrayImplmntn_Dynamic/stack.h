//Stack: Array Implementation, Dynamically created array

typedef struct stack
{
	int *s;
	int top;
	int maxSize;
}STACK;

void initStack(STACK *ps,int n);
void stackDouble(STACK *ps);
int isFull(STACK *ps);
int push(STACK *ps,int ele);
int isEmpty(STACK *ps);
int stackTop(STACK *ps,int *pe);
int pop(STACK *ps,int *pe);
void display(STACK *ps);
void destroyStack(STACK *ps);