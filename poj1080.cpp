#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define maxl 105

char name[6] = "ACGT-";
char gene1[maxl], gene2[maxl];
int len1, len2;
int match[5][5] =
{
{ 5, -1, -2, -1, -3 },
{ -1, 5, -3, -2, -4 },
{ -2, -3, 5, -2, -2 },
{ -1, -2, -2, 5, -1 },
{ -3, -4, -2, -1, 0 } };
int f[maxl][maxl];

void input(int &len, char *gene)
{
    scanf("%d", &len);
    scanf("%s", gene + 1);
}

int get_id(char ch)
{
    for (int i = 0; i < 5; i++)
        if (ch == name[i])
            return i;
    return -1;
}

void work()
{
    f[0][0] = 0;
    for (int i = 1; i <= len1; i++)
        f[i][0] = match[get_id(gene1[i])][get_id('-')] + f[i - 1][0];
    for (int i = 1; i <= len2; i++)
        f[0][i] = match[get_id(gene2[i])][get_id('-')] + f[0][i - 1];
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            f[i][j] = match[get_id(gene1[i])][get_id(gene2[j])]
                    + f[i - 1][j - 1];
            f[i][j] = max(f[i][j],
                    match[get_id(gene1[i])][get_id('-')] + f[i - 1][j]);
            f[i][j] = max(f[i][j],
                    match[get_id(gene2[j])][get_id('-')] + f[i][j - 1]);
        }
    printf("%d\n", f[len1][len2]);
}

int main()
{
    //freopen("t.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input(len1, gene1);
        input(len2, gene2);
        work();
    }
    return 0;
}