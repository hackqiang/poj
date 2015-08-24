#include <iostream>

using namespace std;

int inf=99999;

int N;
int map[28][28];

int lowcost[28]={0};                                         //记录Vnew中每个点到V中邻接点的最短边
int visit[28];                                             //标记某点是否加入Vnew

void Dijkstra(int start)
{
  　　for(int i=1; i<=N; ++i)
 　　 {
		lowcost[i] = map[start][i];
      　　visit[i] = -1;                                // 初始都未用过该点
   　　}
   　 lowcost[start] = 0;
   　 visit[start] = true; 　　
   
 　　 for(int i=2; i<=n; i++)
 　　 {
       　　int minlowcost = inf;
       　　int u = start; 　　                            // 找出当前未使用的点j的lowcost[j]最小值
      　　 for(int j=1; j<=n; ++j)
      　　    if(visit[j]==-1 && lowcost[j]<minlowcost)
      　　    {
         　 　      minlowcost = lowcost[j];
         　　       u = j;                             // u保存当前邻接点中距离最小的点的号码 
       　　   }
       　　visit[u] = true; 
       　　for(int j=1; j<=n; j++)
       　　    if(visit[j]==-1 && map[u][j]<inf)
       　　    {
           　    　if(lowcost[u] + map[u][j] < lowcost[j])     //在通过新加入的u点路径找到离start点更短的路径  
           　    　{
                   　　lowcost[j] = lowcost[u] + map[u][j];    //更新lowcost 
            　　    }
        　    　}
   　　}
}

int main()
{
	int n,l;
	char ch1,ch2;
	int i,j;

	while(cin>>N && N)
	{
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				map[i][j] = inf;

		for(i=1;i<=N-1;i++)
		{
			cin>>ch1>>n;
			for(j=0;j<n;j++)
			{
				cin>>ch2>>l;
				map[ch1-'A'+1][ch2-'A'+1] = l;
				map[ch2-'A'+1][ch1-'A'+1] = l;
			}
		}
#if 0
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}
#endif

		cout<<prim()<<endl;
	}
	return 0;
}