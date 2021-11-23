#define MAX 20
typedef struct stack
{
	float s[MAX];
	int top;
}STACK;

float postfixEval(char*);