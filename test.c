#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct trienode
{
    struct trienode *child[26];
    int endofword;
};

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Node
{
    int data;
    struct node *next, *prev;
} Node;

typedef struct dll
{
    Node *head;
} dll;

typedef struct stack
{
    int s[MAX];
    int top;
} STACK;

typedef struct NODE
{
    int info;
    struct node *left, *right;
    int left_thread
} NODE;

typedef struct tree
{
    NODE *root;
} TREE;

void initStack(STACK *ps)
{
    ps->top = -1;
}

int isFull(STACK *ps)
{
    return ps->top == MAX - 1;
}

int push(STACK *ps, int ele)
{
    if (isFull(ps))
        return 0;
    //Next two lines: or ps->s[++ps->top]=ele
    ps->top++;
    ps->s[ps->top] = ele;
    return 1;
}

int intersect()
{
    STACK s1, s2;
    node *p, *q;
    while (p != NULL && q != NULL)
    {
        if (p->data == q->data)
        {
            printf("intersection is ");
        }
        else if (p->data > q->data)
        {
            push(&s2, q->data);
            q = q->next;
        }
        else
        {
            push(&s1, p->data);
            p = p->next;
        }
    }
}

void convert_eval(char *infix)
{
    STACK operator, operand;
    while (*infix != '\0')
    {
        if (isOperand(*infix))
            push(&operand, *infix);
        else if (isOperator(*infix))
            push(&operator, * infix);
        else if (*infix == ')')
        {
            int op = pop(&operator);
            while (op != '(')
            {
                int a = pop(&operand);
                int b = pop(&operand);
                int result = evaluate(a, b, op);
                push(&operand, result);
                op = pop(&operator);
            }
        }
        infix++;
    }
}

int to_check(node *first, node *second)
{
    node *p = first;
    node *q = second;
    int c = 0;
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
            q = q->next;
        else if (p->data < q->data)
            p = p->next;
        else
            c++;
    }
    return c;
}

void sum(dll *d)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = d->head->data + d->head->next->data;
    temp->next=d->head->next->next;
    temp->prev=NULL;

    
}
int main()
{

    return 0;
}