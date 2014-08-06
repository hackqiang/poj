//Memory Time 
//388K   16MS 
/*

�������⣺

��ңԶ�Ĺ��ҷ��޲����ǣ��ӷ��Ƿ�������������ž��������������ɷ��ٴӹ�������ѡ�ġ��������ѡn ������Ϊ�����ŵĺ�ѡ�ˣ�Ȼ���ٴ���n ������ѡm ����������š�ѡm �˵İ취�ǣ��ط��ͱ緽����ݶԺ�ѡ�˵�ϲ���̶ȣ������к�ѡ�˴�֣���ֵ��0 ��20��Ϊ�˹�ƽ���������ѡ�������ŵ�ԭ���ǣ�ѡ����m ���ˣ���������緽�ܷ�D�Ϳط��ܷ�P�Ĳ�ľ���ֵ|D-P|��С������ж���ѡ�񷽰��� |D-P| ֵ��ͬ����ôѡ���˫���ܷ�֮��D+P���ķ������ɡ�

�����

ѡȡ��������������m����ѡ�˺�Ҫ�������m���˵ı緽��ֵD�Ϳط���ֵP��������������ǵı�š�

*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n;  //��ѡ����
int m;  //��ѡ����
int dp[21][801];   //dp[j][k]��ȡj����ѡ�ˣ�ʹ���ز�Ϊk�����з����У���غ����ķ����ı�غ�
int path[21][801];  //��¼��ѡ���ĺ�ѡ�˵ı��

/*���ݣ�ȷ��dp[j][k]�����Ƿ���ѡ�����ѡ��i*/
bool select(int j,int k,int i,int* v)
{
	while(j>0 && path[j][k]!=i)
	{
		k-=v[ path[j][k] ];
		j--;
	}
	return j?false:true;
}

int main(void)
{
	int time=1;
	while(cin>>n>>m && n)
	{
		/*Initial*/

		int j,k,i;
		int* p=new int[n+1];  //ÿ���˵Ŀط�ֵ
		int* d=new int[n+1];  //ÿ���˵ı緽ֵ
		int* s=new int[n+1];  //ÿ���˵ı�غ�
		int* v=new int[n+1];  //ÿ���˵ı�ز�
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		
		/*Input*/

		for(i=1;i<=n;i++)
		{
			cin>>p[i]>>d[i];

			s[i]=p[i]+d[i];
			v[i]=p[i]-d[i];
		}
		int fix=m*20;  //������ֵ����������Ϊ��[-400,400]ӳ�䵽[0,800]

		/*DP*/

		dp[0][fix]=0;   //������������ֵ�����dp[0][fix]����������dp[0][0]
		for(j=1;j<=m;j++)
			for(k=0;k<=2*fix;k++)
			{
				if(dp[j-1][k]>=0)   //������ƽ�ƣ�dp[0][fix]����������dp[0][0]
				{
					for(i=1;i<=n;i++)
						if(dp[j][ k+v[i] ] < dp[j-1][k]+s[i])
						{
							if(select(j-1,k,i,v))
							{
								dp[j][ k+v[i] ] = dp[j-1][k]+s[i];
								path[j][ k+v[i] ] = i;
							}
						}
				}
			}


		/*Output*/

		for(k=0;k<=fix;k++)
			if(dp[m][fix-k]>=0 || dp[m][fix+k]>=0)    //���м�������������С��ز��λ��k
				break;

		int div=dp[m][fix-k] > dp[m][fix+k] ? (fix-k):(fix+k);  //��С��ز�

		cout<<"Jury #"<<time++<<endl;
		cout<<"Best jury has value ";
		//�緽��ֵ = ����غ�+��ز�+����ֵ��/2
		cout<<(dp[m][div]+div-fix)/2<<" for prosecution and value ";
		//�ط���ֵ = ����غ�-��ز�+����ֵ��/2
		cout<<(dp[m][div]-div+fix)/2<<" for defence:"<<endl;

		int* id=new int[m];
		for(i=0,j=m,k=div;i<m;i++)
		{
			id[i]=path[j][k];
			k-=v[ id[i] ];
			j--;
		}
		sort(id,id+m);   //���������ѡ�˱��
		for(i=0;i<m;i++)
			cout<<' '<<id[i];
		cout<<endl<<endl;

		/*Relax*/

		delete p;
		delete d;
		delete s;
		delete v;
		delete id;
	}
	return 0;
}