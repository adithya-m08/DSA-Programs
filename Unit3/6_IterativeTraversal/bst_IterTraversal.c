#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node
{
	int info;
	struct node *left,*right;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;

typedef struct stack
{
	int top;
	NODE* s[MAX];
}STACK;
typedef struct queue
{
	int rear,front;
	NODE* q[MAX];
}QUEUE;
void initTree(TREE* pt)
{
	pt->root=NULL;
}

void createTree(TREE *pt)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->left=temp->right=NULL;
	
	printf("Enter root info\n");
	scanf("%d",&temp->info);
	
	pt->root=temp;
	
	int choice;
	printf("Do you want to add one more node\n");
	scanf("%d",&choice);
	
	while(choice)
	{
		NODE *temp=malloc(sizeof(NODE));
		temp->left=temp->right=NULL;
	
		printf("Enter node info\n");
		scanf("%d",&temp->info);
		
		NODE *p=pt->root;
		NODE *q;
		
		while(p!=NULL)
		{
			q=p;
			if(temp->info < p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(temp->info < q->info)
			q->left=temp;
		else
			q->right=temp;
		
		printf("Do you want to add one more node\n");
		scanf("%d",&choice);
	}
}
void push(STACK *ps,NODE *ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
}
NODE *pop(STACK *ps)
{
	NODE *temp=ps->s[ps->top];
	ps->top--;
	return temp;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
void inorder(TREE *pt)
{
	STACK s;
	s.top=-1;
	
	NODE *cur=pt->root;

	while(!isEmpty(&s)||cur!=NULL)
	{
		if(cur!=NULL)
		{
			push(&s,cur);
			cur=cur->left;
		}
		else
		{
			cur=pop(&s);
			printf("%d ",cur->info);
			cur=cur->right;
		}
	}
}

void preorder(TREE *pt)
{
	STACK s;
	s.top=-1;
	NODE *cur=pt->root;
	
	if(cur==NULL)
		return;
	
	push(&s,cur);
	while(!isEmpty(&s))
	{
		cur=pop(&s);
		printf("%d ",cur->info);
		if(cur->right!=NULL)
			push(&s,cur->right);
		if(cur->left!=NULL)
			push(&s,cur->left);
	}
}
void postorder(TREE *pt)
{
	STACK s1,s2;
	s1.top=-1;
	s2.top=-1;
	
	NODE *cur=pt->root;
	
	if(cur==NULL)
		return;
	
	push(&s1,cur);
	while(!isEmpty(&s1))
	{
		cur=pop(&s1);
		push(&s2,cur);
		
		if(cur->left!=NULL)
			push(&s1,cur->left);
		if(cur->right!=NULL)
			push(&s1,cur->right);
	}
	while(!isEmpty(&s2))
	{
		cur=pop(&s2);
		printf("%d ",cur->info);
	}
}
void enqueue(QUEUE* pq,NODE* ele)
{
	pq->rear++;
	pq->q[pq->rear]=ele;
}

NODE* dequeue(QUEUE* pq)
{
	NODE* ele=pq->q[pq->front];
	pq->front++;
	
	if(pq->front>pq->rear)
	{
		pq->front=0;
		pq->rear=-1;
	}
	return ele;
	
	//return pq->q[pq->front++];
}

int isEmptyQ(QUEUE *pq)
{
	return pq->front>pq->rear;
}
void levelorder(TREE *pt)
{
	QUEUE q;
	q.front=0;
	q.rear=-1;
	NODE *cur=pt->root;
	
	if(cur==NULL)
		return;
	
	enqueue(&q,cur);
	while(!isEmptyQ(&q))
	{
		cur=dequeue(&q);
		printf("%d ",cur->info);
		if(cur->left!=NULL)
			enqueue(&q,cur->left);
		if(cur->right!=NULL)
			enqueue(&q,cur->right);
	}
}
void destroyNode(NODE *r)
{
	if(r!=NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		printf("\nFreeing %d",r->info);
		free(r);
	}
}
void destroyTree(TREE *pt)
{
	if(pt->root!=NULL)
	{
		destroyNode(pt->root);
		pt->root=NULL;
	}
}

int main()
{
	TREE tobj;
	initTree(&tobj);
	createTree(&tobj);
	printf("Inorder");
	inorder(&tobj);
	printf("\nPreorder");
	preorder(&tobj);
	printf("\nPostorder");
	postorder(&tobj);
	printf("\nLevelorder");
	levelorder(&tobj);
	printf("\n");
	destroyTree(&tobj);
}