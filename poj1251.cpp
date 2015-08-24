#include <iostream>

using namespace std;

int inf=99999;

int N;
int map[28][28];

int lowcost[28]={0};                                         //记录Vnew中每个点到V中邻接点的最短边
int visit[28];                                             //标记某点是否加入Vnew

int prim(int start)
{
     int sumweight=0;
     int i,j,k=0;

     for(i=1;i<=N;i++)                                      //顶点是从1开始
     {
        lowcost[i]=map[start][i];
        visit[i]=-1;                                         //将所有点至于Vnew之外,V之内，这里只要对应的为-1，就表示在Vnew之外
     }

	visit[start]=0;                                        //将起始点start加入Vnew
	

	for(i=1;i<=N;i++)
	{
		int minx = inf;
		int v = -1;
		for(j=1; j<=N;j++)
		{
			if(visit[j]==-1&&lowcost[j]<minx)
			{
                minx=lowcost[j];
                v=j;
			}
		}
		if(v!=-1)
		{
            //printf("%d %d %d\n",adjecent[v],v,lowcost[v]);
            visit[v]=0;                                      //将v加Vnew中

            //sumweight+=lowcost[v];                             //计算路径长度之和
            for(j=1;j<=N;j++)
            {
                if(visit[j]==-1&&map[v][j]<lowcost[j])      
                {
                    lowcost[j]=map[v][j];                     //此时v点加入Vnew 需要更新lowcost                           
                }
            }
		}

	}
  
  for(j=2;j<=N;j++)
	  sumweight+=lowcost[j];
    return sumweight;  

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

		cout<<prim(1)<<endl;
	}
	return 0;
}