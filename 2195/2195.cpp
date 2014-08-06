#include<iostream>
#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int Max = 205;
const int inf = 9999999;

 

struct{
    int r, c;
}man[Max], hou[Max];
int M, H, n, m;           //  n为X集合顶点数量，m为Y集合顶点数量。(1~n和1~m)
int map[Max][Max];        //  map[i][j]：记录X集合中的i到Y集合中的j所需的费用。
int lx[Max], ly[Max];
int link[Max];
bool x[Max], y[Max];

 

bool dfs(int u){          //  判断能否找到最大完全匹配。
    x[u] = true;
    for(int v = 1; v <= m; v++)
        if(!y[v] && lx[u] + ly[v] == map[u][v]){
            y[v] = true;
            if(!link[v] || dfs(link[v])){
                link[v] = u;
                return true;
            }
        }
    return false;
}

 

int KM(){                 //  KM算法。
    int i, j, k, mi;
    for(i = 1; i <= n; i ++)
        for(lx[i] = -inf, j = 1; j <= m; j ++)       
            lx[i] = max(lx[i], map[i][j]);
    memset(ly, 0, sizeof(ly));
    memset(link, 0, sizeof(link));
    for(i = 1; i <= n; i++){
        while(1){
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if(dfs(i)) break;
            mi = inf;
            for(j = 1; j <= n; j++)
                if(x[j])
                    for(k = 1; k <= m; k++)
                        if(!y[k])
                            mi = min(mi, lx[j] + ly[k] - map[j][k]);
            for(j = 1; j <= n; j ++) if(x[j]) lx[j] -= mi;
            for(j = 1; j <= m; j ++) if(y[j]) ly[j] += mi;
        }
    }
    int ans = 0;
    for(i = 1; i <= m; i++)
        if(link[i] > 0)
            ans += map[link[i]][i];
    return ans;
}

 

int main(){
    int row, col, i, j;
    char ch;
    while(cin >> row >> col){
        if(row == 0 && col == 0) break;
        M = 0, H = 0;
        for(i = 0; i < row; i ++)
            for(j = 0; j < col; j ++){
                cin >> ch;
                if(ch == 'm'){
                    man[++ M].r = i;
                    man[M].c = j;
                }else if(ch == 'H'){
                    hou[++ H].r = i;
                    hou[H].c = j;
                }
            }
        n = m = M;
        for(int i = 1; i <= M; i ++)      //  KM算法是求最大权，故这里存负数，最后取反求最小权。
            for(int j = 1; j <= H; j ++)
                map[i][j] = -abs(man[i].r-hou[j].r)-abs(man[i].c-hou[j].c);
        cout << -KM() << endl;
    }
    return 0;
}


