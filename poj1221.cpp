#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 252

int n;
long long f[maxn][maxn];    //f[sum][last value]
long long ans[maxn];

void init()
{
    memset(f, 0, sizeof(f));
    for (int i = 0; i < maxn; i++)
        f[0][i] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i][j - 1] + f[i - j][min(j, i - j)];
    for (int i = 1; i < maxn; i++)
    {
        if ((i & 1) == 0)
            ans[i] = f[i / 2][i / 2];
        else
            ans[i] = 0;
        for (int j = i; j >= 1; j -= 2)
            ans[i] += f[(i - j) / 2][min(j, (i - j) / 2)];
    }
}

int main()
{
    init();
    while (scanf("%d", &n), n)
        printf("%d %lld\n", n, ans[n]);
    return 0;
}