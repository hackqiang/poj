#include<iostream>
using namespace std;
int a[105][105],m[105][105][105];
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			cin>>a[i][j]; 
			m[i][i][j]=a[i][j];//�����ԭ���Ĳ���Ҫ������
		}
	for(i=1; i<=n; i++)//ָ�����еĲ�����
	{ 
		 for(j=1; j<=n; j++)//������ǵ�i�еĴ�j��k�еĺȵ�
			 for(k=j+1; k<=n; k++)
			 {
				 m[j][k][i]=m[j][k-1][i]+a[k][i];
			 }
	}
	int Max=0;//������¼�����������ľ���ĺ͵�
	for(i=1; i<=n; i++)
		for(j=i; j<=n; j++)
		{
			for(k=2; k<=n; k++)
				if(m[i][j][k-1]>0)
					m[i][j][k]+=m[i][j][k-1];
			for(k=1; k<=n; k++)
				if(m[i][j][k]>Max)
					Max=m[i][j][k];
		}
	cout<<Max<<endl;
	return 0;
}