#define MAX 30
typedef struct stack
{
	char s[MAX];
	int top;
}STACK;

void infixToPostfix(char*,char*);