#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int VM=110;
const int INF=999999999;

struct Edge{
    int u,v;
    int s;
}edge[VM*VM];

int n,m,ans,f[VM];

void initf(){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
}

int getf(int i)
{
    if(i!=f[i])
        f[i] = getf(f[i]);
    return f[i];
}

void quicksort(int left, int right)
{
    if(left>=right)
        return;
    
    int low = left, high = right;
    Edge t = edge[left];
    
    while(low<high)
    {
        while(low<high && edge[high].s >= t.s)
            high--;
        edge[low] = edge[high];
        
        while(low<high && edge[low].s <= t.s)
            low++;
        edge[high] = edge[low];
    }
    
    edge[low] = t;
    quicksort(left, low-1);
    quicksort(low+1, right);
}

int Kruskal(int i)
{
    int count = 0;
    initf();  
    for(int j=i; j<m;j++)
    {
        int uf = getf(edge[j].u);
        int vf = getf(edge[j].v);
        if(uf!=vf)
        {
            count++;
            f[vf] = uf;
        }
        if(count == n-1)
        {
            return edge[j].s - edge[i].s;
        }
    }
    return -1;
}

int main(){

    //freopen("in.txt","r",stdin);

    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0)
            break;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].s);
        ans=INF;
        quicksort(0,m-1);
        for(int i=0;i<m;i++)
        {
            int tmp;
            tmp = Kruskal(i);
            if(tmp == -1)
            {
                break;
            }
            else
            {
                if(ans > tmp)
                    ans  = tmp;
            }
            
        }
        if(ans==INF)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}