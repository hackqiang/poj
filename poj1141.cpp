#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
usingnamespace std;

#define maxn 300

char st[maxn];
int f[maxn][maxn], v[maxn][maxn];

bool match(char a, char b)
{
    if (a =='('&& b ==')')
        returntrue;
    if (a =='['&& b ==']')
        returntrue;
    returnfalse;
}

char other(char a)
{
    if (a =='(')
        return')';
    if (a =='[')
        return']';
    if (a ==')')
        return'(';
    return'[';
}

void output(int s, int e)
{
    if (s > e)
        return;
    if (s == e)
    {
        if (st[s] =='('|| st[s] ==')')
            printf("()");
        else
            printf("[]");
        return;
    }
    if (v[s][e] ==-1)
    {
        putchar(st[s]);
        output(s +1, e -1);
        putchar(st[e]);
        return;
    }
    output(s, v[s][e]);
    output(v[s][e] +1, e);
}

int main()
{
    //freopen("t.txt", "r", stdin);
if (gets(st) == NULL)
        return0;
    int len = strlen(st);
    memset(f, -1, sizeof(f));
    memset(v, -1, sizeof(v));
    for (int i =0; i < len; i++)
    {
        f[i][i] =1;
        f[i +1][i] =0;
    }
    for (int i =1; i < len; i++)
    {
        for (int j =0; j < len - i; j++)
        {
            int s = j, e = j + i;
            if (match(st[s], st[e]))
                f[s][e] = f[s +1][e -1];
            for (int k = s; k < e; k++)
                if (f[s][e] > f[s][k] + f[k +1][e] || f[s][e] ==-1)
                {
                    f[s][e] = f[s][k] + f[k +1][e];
                    v[s][e] = k;
                }
        }
    }
    output(0, len -1);
    putchar('\n');
    return0;
}