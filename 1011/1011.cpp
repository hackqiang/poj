#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 64

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


int main()
{
	int n = 0;
	while(cin>>n)
	{
		if(n == 0)
			break;
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			cin>>stick[i];
			sum += stick[i];
			visit[i]  = 0;
		}

		sort(stick, stick+n, greater<int>());
		int max_sticks = sum/stick[0];
		int flag = 0;
		while(max_sticks>1)
		{
			if(sum%max_sticks == 0)
			{
				int size = sum/max_sticks;
				//cout<<"xx"<<size<<endl;
				if(dfs(n, size, 0, 0, max_sticks, 0))
				{
					cout<<size<<endl;
					flag = 1;
					break;
				}					
			}
			--max_sticks;
		}
		if(!flag)
			cout<<sum<<endl;
	}

	return 0;
}
