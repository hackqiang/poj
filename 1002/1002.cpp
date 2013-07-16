#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 0-9 --> 48-57
// A-Z --> 65-90
char c_map[43] = {0,1,2,3,4,5,6,7,8,9,
					0,0,0,0,0,0,0,
					2,2,2,
					3,3,3,
					4,4,4,
					5,5,5,
					6,6,6,
					7,7,7,7,
					8,8,8,
					9,9,9,9};

int str2num(string data)
{
	int num = 0;
	for(int i = 0,j =6; i < data.size() && j>=0; i++)
	{
		if(data[i]!='-')
		{
			//cout<<data[i]-48<<" ";
			num *= 10;
			num += c_map[data[i]-48];
			j--;
		}
	}
	//cout<<endl;
	return num;
}


int main()
{
	string data;
	int n;
	cin>>n;
	vector<int> db;

	while(cin>>data)
	{
		int num = str2num(data);
		db.push_back(num);
		data.clear();
	}
	sort(db.begin(), db.end());
	int flag = 0;
	int count = 1;
	int i = 0;
	n--;
	for(i=0; i<n;)
	{
		while(db[i]==db[i+1])
		{
			count++;
			i++;
		}
		if(count>1)
		{
			cout<<setw(3)<<setfill('0')<<db[i]/10000<<"-"<<setw(4)<<setfill('0')<<db[i]%10000<<" "<<count<<endl;
			flag = 1;
			count = 1;
		}
		i++;
	}
	if(!flag)
		cout<<"No duplicates."<<endl;
	return 0;
}