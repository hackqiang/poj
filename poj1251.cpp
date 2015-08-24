#include <iostream>

using namespace std;

int inf=99999;

int N;
int map[28][28];

int lowcost[28]={0};                                         //��¼Vnew��ÿ���㵽V���ڽӵ����̱�
int visit[28];                                             //���ĳ���Ƿ����Vnew

int prim(int start)
{
     int sumweight=0;
     int i,j,k=0;

     for(i=1;i<=N;i++)                                      //�����Ǵ�1��ʼ
     {
        lowcost[i]=map[start][i];
        visit[i]=-1;                                         //�����е�����Vnew֮��,V֮�ڣ�����ֻҪ��Ӧ��Ϊ-1���ͱ�ʾ��Vnew֮��
     }

	visit[start]=0;                                        //����ʼ��start����Vnew
	

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
            visit[v]=0;                                      //��v��Vnew��

            //sumweight+=lowcost[v];                             //����·������֮��
            for(j=1;j<=N;j++)
            {
                if(visit[j]==-1&&map[v][j]<lowcost[j])      
                {
                    lowcost[j]=map[v][j];                     //��ʱv�����Vnew ��Ҫ����lowcost                           
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