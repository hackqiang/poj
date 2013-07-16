#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define N 256

void removezero(string *str)
{
	string::size_type i = 0;
	while(str->at(i) =='0')
	{
		i++;
	}
	if(i!=0)
		str->erase(0, i);

	i = str->size() - 1;
	while(str->at(i) =='0')
	{
		i--;
	}
	//cout<<str->size() - 1<<i<<endl;
	//cout<<*str<<endl;
	if(i != str->size() - 1)
		str->erase(i+1, str->size() -1 - i);
}


void pnum(int *num, int dots)
{
	int i = N-1;
	while(!num[i--]);
	i++;
	if(dots >= i + 1)
	{
		cout<<".";
		for(int j = 0; j<dots - i -1; j++)
			cout<<0;
		dots = 0;
	}
	
	for(int j = i; j>=0; j--)
	{
		cout<<num[j];
		if(dots && j == dots)
			cout<<".";
	}

	cout<<endl;
}

void time_2(int *a, int *b)
{
	int sum[N] = {0};
	for(int i=0; i<N/2; i++)
	{
		for(int j = 0; j<N/2; j++)
		{
			sum[j+i]+=a[i]*b[j];
		}
	}
	
	for(int i = 0; i<N; i++)
	{
		sum[i+1] += sum[i]/10;
		sum[i] = sum[i]%10;
	}
	
	memcpy(a, sum, sizeof(int)*N);
}

int main()
{
	string fstr;
	int exp;
	while(cin>>fstr>>exp)
	{
		removezero(&fstr);
		string::size_type bits = fstr.size() - fstr.find(".") - 1;
		fstr.erase(fstr.find("."), 1);
		string::size_type n = fstr.size();
		//cout<<fstr<<" "<<bits<<" "<<exp<<" "<<n<<endl;
		int num[N] = {0};
		int sum[N] = {0};
		sum[0] = 1; 
		int i = 0;
		while(n)
		{
			num[i++] = fstr[n-1] - '0';
			n--;
		}
		//pnum(num, bits);
		int j;
		for(j = 0; j < exp; j++)
		{
			time_2(sum, num);
		}
		bits = bits*exp;
		pnum(sum, bits);
		fstr.clear();
	}	
	return 0;
}