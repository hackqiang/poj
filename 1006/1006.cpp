#include <iostream>
using namespace std;

int main()
{
	int p,e,i,d;
	int caseid = 1;
	while(cin>>p>>e>>i>>d)
	{
		//cout<<p<<" "<<e<<" "<<i<<" "<<d<<endl;
		if(p == -1 && e == -1 && i == -1 && d == -1)
			break;
		p%=23;
		e%=28;
		i%=33;
		int n = d+1;
		while(n<21252+d+1)
		{
			if((n-p)%23==0 && (n-e)%28==0 && (n-i)%33==0)
				break;
			n++;
		}
		cout<<"Case "<<caseid++<<": the next triple peak occurs in "<<n-d<<" days."<<endl;
	}
	
	return 0;
}