#include <iostream>

using namespace std;

int inf=99999;

int N;
int map[28][28];

int lowcost[28]={0};                                         //��¼Vnew��ÿ���㵽V���ڽӵ����̱�
int visit[28];                                             //���ĳ���Ƿ����Vnew

void Dijkstra(int start)
{
  ����for(int i=1; i<=N; ++i)
 ���� {
		lowcost[i] = map[start][i];
      ����visit[i] = -1;                                // ��ʼ��δ�ù��õ�
   ����}
   �� lowcost[start] = 0;
   �� visit[start] = true; ����
   
 ���� for(int i=2; i<=n; i++)
 ���� {
       ����int minlowcost = inf;
       ����int u = start; ����                            // �ҳ���ǰδʹ�õĵ�j��lowcost[j]��Сֵ
      ���� for(int j=1; j<=n; ++j)
      ����    if(visit[j]==-1 && lowcost[j]<minlowcost)
      ����    {
         �� ��      minlowcost = lowcost[j];
         ����       u = j;                             // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ��� 
       ����   }
       ����visit[u] = true; 
       ����for(int j=1; j<=n; j++)
       ����    if(visit[j]==-1 && map[u][j]<inf)
       ����    {
           ��    ��if(lowcost[u] + map[u][j] < lowcost[j])     //��ͨ���¼����u��·���ҵ���start����̵�·��  
           ��    ��{
                   ����lowcost[j] = lowcost[u] + map[u][j];    //����lowcost 
            ����    }
        ��    ��}
   ����}
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