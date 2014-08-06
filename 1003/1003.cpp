#include <iostream>

using namespace std;

int main()
{
	float data;
	while(cin>>data)
	{
		int i = 2;
		float fres = 0.0;
		long long res = 0;
		long long cp = (long long)((float)data*1000000);
		int n=10;
		if(cp == 0)
			break;
		while(res<cp)
		{
			res += ((float)1/i)*1000000;
			//cout<<"i"<<i<<" "<<res<<endl;
			i++;
		}
		cout<<i-2<<" card(s)"<<endl;
	}
	return 0;
}