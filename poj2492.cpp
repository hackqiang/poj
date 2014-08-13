#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxm 2000005
#define maxn 2005

struct Edge
{
    int v, next;
} edge[maxm];

int m, n;
int count, head[maxn];
int q[maxn], front, rear;
int sex[maxn];

void addedge(int a, int b)
{
    edge[count].next = head[a];
    edge[count].v = b;
    head[a] = count;
    count++;
    edge[count].next = head[b];
    edge[count].v = a;
    head[b] = count;
    count++;
}

void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        addedge(a, b);
    }
}

bool bfs(int s)
{
    q[0] = s;
    front = 0;
    rear = 1;
    sex[s] = 0;
    while (front != rear)
    {
        int a = q[front++];
        if (front == maxn)
            front = 0;
        for (int i = head[a]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (sex[v] == -1)
            {
                sex[v] = 1 - sex[a];
                q[rear++] = v;
                if (rear == maxn)
                    rear = 0;
                continue;
            }else if (sex[v] == sex[a])
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("t.txt", "r", stdin);
    int t, s = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(head, -1, sizeof(head));
        memset(sex, -1, sizeof(sex));
        count = 0;
        s++;
        printf("Scenario #%d:\n", s);
        input();
        bool ans = true;
        for (int i = 0; i < n && ans; i++)
            if (sex[i] == -1)
                ans = bfs(i);
        if (ans)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}