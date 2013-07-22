#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getdata(vector<pair<int, int> > &buffer, int n, int index);
int getmax2(vector<pair<int, int> > &buffer, int n, int sum, int index);


void debug_p_pairs(vector<pair<int, int> > &buffer, int n)
{
	cout<<n<<endl;
	int ix = 0;
	for(ix = 0; ix != buffer.size(); ++ix)
	{
		cout<<buffer[ix].first<<" "<<buffer[ix].second<<endl;
	}
}

void debug_p_bitmap(vector<pair<int, int> > &buffer, int n, int sum)
{
	for(int i =0;i<sum;i++)
	{
		cout<<getdata(buffer, n, i)<<" ";
		if((i+1)%n == 0)
			cout<<endl;
	}
	for(int i =0;i<sum;i++)
	{
		cout<<getmax2(buffer, n, sum, i)<<" ";
		if((i+1)%n == 0)
			cout<<endl;
	}
}


int getdata(vector<pair<int, int> > &buffer, int n, int index)
{
	int sum = 0;
	int ix = 0;
	while( ix != buffer.size() && sum < index+1)
	{
		sum += buffer[ix].second;
		++ix;
	}
	return buffer[ix-1].first;	
}


int getmax2(vector<pair<int, int> > &buffer, int n, int sum, int index)
{
	//return 0;  //still timeout???
	int max = 0;
	int top = index, pre = index, next = index, bom = index;
	int toppre = index, topnext = index, bompre = index, bomnext = index;
	if(index-n-1 > -1  && index%n != 0)
		toppre = index - n - 1;
	if(index-n > -1)
		top = index - n;
	if(index-n+1 > -1 && (index+1)%n !=0)
		topnext = index - n + 1;
	if(index - 1 > -1 && index%n != 0)
		pre = index - 1;
	if((index+1)%n !=0 && index+1 < sum)
		next = index + 1;
	if(index+n-1 < sum && index%n != 0)
		bompre = index + n - 1;	
	if(index+n < sum)
		bom = index + n;
	if(index+n+1 < sum && (index+1)%n !=0)
		bomnext = index + n + 1;

	int data = getdata(buffer, n, index);
	int t_sum1 = 0;
	int t_sum2 = 0;
	for(vector<pair<int, int> >::size_type ix = 0; ix != buffer.size(); ++ix)
	{
		//cout<<buffer[ix].first<<" "<<buffer[ix].second<<endl;
		t_sum2 = t_sum1 + buffer[ix].second;
		if(toppre!=index && toppre+1>=t_sum1 && toppre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			toppre = index;
		}
		if(top!=index && top+1>=t_sum1 && top+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			top = index;
		}
		if(topnext!=index && topnext+1>=t_sum1 && topnext+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			topnext = index;
		}
		if(pre!=index && pre+1>=t_sum1 && pre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			pre = index;
		}
		if(next!=index && next+1>=t_sum1 && next+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			next = index;
		}
		if(bompre!=index && bompre+1>=t_sum1 && bompre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			bompre = index;
		}
		if(bom!=index && bom+1>=t_sum1 && bom+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			bom = index;
		}
		if(bomnext!=index && bomnext+1>=t_sum1 && bomnext+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].first - data))
				max = fabs(buffer[ix].first - data);
			bomnext = index;
			break;
		}
		t_sum1 = t_sum2;
	}
	return max;
}

void deal_pairs(vector<pair<int, int> > &buffer, int n, int sum)
{
	int t_index = 0;
	int num = 0;
	int pre_num = getmax2(buffer, n, sum, 0);
	int nums = 0;
	for(int ix = 0; ix != buffer.size(); ++ix)
	{
		//cout<<buffer[ix].first<<" "<<buffer[ix].nums<<endl;
		int row = 0;
		int flag = 0;
		for(int xxx = 0; xxx<buffer.size(); ++xxx)
		{
			if(buffer[xxx].second%n)
				flag = 1;
		}
		if(!flag)
		{
			row = buffer[ix].second/n;
			if(row > 1)
			{
				if(ix == 0)
				{
					if(ix == buffer.size() -1)
					{
						cout<<0<<" "<<buffer[ix].second<<endl;
						break;
					}
					else
						cout<<0<<" "<<n*(row-1)<<endl;
				}
				else
				{
					cout<<fabs(buffer[ix].first - buffer[ix-1].first)<<" "<<2*n<<endl;
					if(row>2)
					{
						if(ix == buffer.size() -1)
						{
							//num = 0;
							//nums += n*(row-1);
							cout<<0<<" "<<n*(row-1)<<endl;
						}
						else
						{
							//num = 0;
							//nums += n*(row-2);
							cout<<0<<" "<<n*(row-2)<<endl;
						}	
					}
				}
			}
			else if(row == 1)
			{
				if(ix == 0)
				{
					if(ix == buffer.size() -1)
					{
						pre_num = num = buffer[ix].first;
						nums += n;
						//cout<<buffer[ix].first<<n<<endl;
						break;
					}
					else
					{
						pre_num = num = fabs(buffer[ix].first - buffer[ix+1].first);
						nums += n;
						//cout<<fabs(buffer[ix].first - buffer[ix+1].first)<<" "<<n<<endl;
					}
				}
				else
				{
					int max = fabs(buffer[ix].first - buffer[ix-1].first);
					if(ix != buffer.size() -1)
					{
						if(max < fabs(buffer[ix].first - buffer[ix+1].first))
							max = fabs(buffer[ix].first - buffer[ix+1].first);
						num = max;
						nums += n;
						//cout<<max<<" "<<n<<endl;
					}
					else
					{
						num = fabs(buffer[ix].first - buffer[ix-1].first);
						nums += n;
						//cout<<fabs(buffer[ix].first - buffer[ix-1].first)<<" "<<n<<endl;
					}
				}
			}
			if(num!=pre_num)
			{
				cout<<pre_num<<" "<<nums<<endl;
				pre_num = num;
				nums = 0;
			}
			continue;
		}
		for(int i = 0; i<buffer[ix].second; i++)
		{
			if(i==n+2 && buffer[ix].second> 2*n+4)
			{
				nums += buffer[ix].second - 2*n -3;
				t_index += buffer[ix].second - 2*n -3;
				i += buffer[ix].second - 2*n -4;
				//cout<<"yyyyyy"<<ix<<" i"<<i<<endl;
				continue;
			}
			if(i == buffer[ix].second - n +1)
			{
				if(ix < buffer.size()-1 && buffer[ix].second>=n && buffer[ix+1].second>=n)
				{
					nums += n-1;
					t_index += n-1;
					i += n-2;
					//cout<<"xxxx"<<ix<<" i"<<i<<endl;
					continue;
				}
			}
			num = getmax2(buffer, n, sum, t_index);
			if(num!=pre_num)
			{
				cout<<pre_num<<" "<<nums<<endl;
				pre_num = num;
				nums = 0;
			}
			nums++;
			t_index++;
		}
	}
	if(nums)
		cout<<pre_num<<" "<<nums<<endl;
}
		
int main()
{
	int n = 0;

	while(cin>>n)
	{
		if(n == 0)
			break;
		cout<<n<<endl;
		vector<pair<int, int> > buffer;
		int nums = 0;
		int num = 0;
		int sum = 0;
		while(cin>>num>>nums)
		{
			if(num == 0 && nums == 0)
				break;
			sum += nums;
			buffer.push_back(make_pair(num, nums));
		}
		//debug_p_pairs(buffer, n);
		//debug_p_bitmap(buffer, n, sum);
		deal_pairs(buffer, n, sum);
		cout<<0<<" "<<0<<endl;

	}
	cout<<0<<endl;
	return 0;
}