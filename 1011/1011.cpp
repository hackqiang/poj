#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 50

#define DEBUG

int check(int data[], int n, int size, int sticks)
{
	cout<<"n "<<n<<" size "<<size<<" sticks "<<sticks<<endl;
	int flag[MAX_SIZE] = {1};
	return 0;
}

int solve(int data[], int n, int sum)
{
	sort(data, data+n, greater<int>());
#ifdef DEBUG
	for(int i = 0; i<n; ++i)
		cout<<data[i]<<" ";
	cout<<endl;
#endif
	int max_sticks = sum/data[0];
	while(max_sticks>1)
	{
		if(sum%max_sticks == 0)
		{
			int size = sum/max_sticks;
			if(check(data, n, size, max_sticks))
				return size;
		}
		--max_sticks;
	}
	
	return sum;
}



int main()
{
	int n = 0;
	while(cin>>n)
	{
		if(n == 0)
			break;
		int i = 0;
		int sum = 0;
		int data[MAX_SIZE] = {0};
		while( i<n && cin>>data[i])
		{
			sum += data[i];
			++i;
		}
		cout<<solve(data, n, sum)<<endl;
	}
	return 0;
}