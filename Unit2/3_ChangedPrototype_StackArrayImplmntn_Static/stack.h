//Stack: Array Implementation, Statically created array
#define MAX 2
typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
void push(STACK *ps,int ele);
int isEmpty(STACK *ps);
int stackTop(STACK *ps);
int pop(STACK *ps);
void display(STACK *ps);