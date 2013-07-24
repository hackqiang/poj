#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_SIZE 20

int stick[MAX_SIZE];
int visit[MAX_SIZE];


int dfs(int n, int len, int clen, int layer, int layers, int start)
{
	if(layer == layers-1)
		return 1;

    for(int i=start; i<n; i++)
    {
        if(visit[i])
            continue;

		visit[i]=1;
        if(clen + stick[i] < len)
        {
            if(dfs(n,len,clen + stick[i],layer,layers,i+1))
                return 1;
        }
		else if(clen + stick[i] == len)
		{
            if(dfs(n,len,0,layer+1,layers,0))
				return 1;
		}
		visit[i]=0;
		
		if(clen == 0)
			return 0;

		while(stick[i] == stick[i+1] && i < n-2)
			i++;
    }
    return 0;
}



int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(stick, 0, sizeof(stick));
        memset(visit, 0, sizeof(visit));
        int n, sum=0;
        cin>>n;
		int i = 0;
		for(int i=0; i<n; i++)
		{
			cin>>stick[i];
			sum += stick[i];
		}
        sort(stick, stick+n, greater<int>());
        if(sum%4)
        {
            cout<<"no"<<endl;
			continue;
        }
        if(stick[0]>sum/4)
        {
            cout<<"no"<<endl;
			continue;
        }
		if(dfs(n,sum/4,0,0,4,0))
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
    }
}