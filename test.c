void bfs(int a[10][10], int n, int visited[10], int source, int dest)
{
    int a[n];
    int f = 0, r = -1;
    q[++r] = source;
    visited[source] = 1;
    while (f <= r)
    {
        int v = q[f++];
        printf();
        for (int i = 0; i < n; i++)
        {
            if (a[v][i] && !visited[i])
            {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

for (int i = 0; i < n; i++)
{
    if (!visited[i])
}

void bfs(NODE *V[MAX], int n, int visited[MAX], int source)
{
    int q[n];
    int f = 0, r = -1;
    q[++r] = source;
    visited[source] = 1;

    while (f <= r)
    {
        int v = q[f++];
        print();

        node *p = V[v];
        while (p != NULL)
        {
            if (!visited[p->info])
            {
                q[++r] = p->info;
                visited[p->info] = 1;
            }
            p = p->next;
        }
    }
}

void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
    int s[n];
    int top = -1;

    int flag = 0, i;
    s[++top] = source;
    visited[source] = 1;
    printf();

    while (top != -1)
    {
        flag = 0;
        source = s[top];
        for (int i = 0; i < n; i++)
        {
            if (a[source][i] && !visited[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            s[++top] = i;
            visited[i] = 1;
            printf();
        }
        else
            top--;
    }
}

while (curr != null and stack is not empt)
{
    if (curr !null)
    {
        push(st, currr)
            curr left
    }
    else
    {
        cur = pop
                  printf
                      curr -
              right
    }
}

push(root) while (stack not empty)
{
    curr = pop
        printf if (currr ruhgt not null)
            push i if (currr left not null)
                push it
}

push(root) while (stack not nempty)
{
    curr = pop(s1)
        push(s2, curr)

            if (left not null)
                push s1 if (right not null)
                    push s1
}

s2 pop print

    i++ if (ht[index].rno == rno && ht[index].mark == 1)
{
    copy off
        retruern 1
}