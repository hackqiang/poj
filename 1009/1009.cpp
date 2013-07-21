#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct _pairs
{
	int num;
	int nums;
} pairs;

int getdata(vector<pairs> buffer, int n, int index);
int getmax2(vector<pairs> buffer, int n, int sum, int index);


void debug_p_pairs(vector<pairs> buffer, int n)
{
	cout<<n<<endl;
	for(vector<pairs>::size_type ix = 0; ix != buffer.size(); ++ix)
	{
		cout<<buffer[ix].num<<" "<<buffer[ix].nums<<endl;
	}
}

void debug_p_bitmap(vector<pairs> buffer, int n, int sum)
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


int getdata(vector<pairs> buffer, int n, int index)
{
	int sum = 0;
	vector<pairs>::size_type ix = 0;
	while( ix != buffer.size() && sum < index+1)
	{
		sum += buffer[ix].nums;
		++ix;
	}
	return buffer[ix-1].num;	
}


int getmax2(vector<pairs> buffer, int n, int sum, int index)
{
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
	for(vector<pairs>::size_type ix = 0; ix != buffer.size(); ++ix)
	{
		//cout<<buffer[ix].num<<" "<<buffer[ix].nums<<endl;
		t_sum2 = t_sum1 + buffer[ix].nums;
		if(toppre!=index && toppre+1>=t_sum1 && toppre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			toppre = index;
		}
		if(top!=index && top+1>=t_sum1 && top+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			top = index;
		}
		if(topnext!=index && topnext+1>=t_sum1 && topnext+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			topnext = index;
		}
		if(pre!=index && pre+1>=t_sum1 && pre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			pre = index;
		}
		if(next!=index && next+1>=t_sum1 && next+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			next = index;
		}
		if(bompre!=index && bompre+1>=t_sum1 && bompre+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			bompre = index;
		}
		if(bom!=index && bom+1>=t_sum1 && bom+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			bom = index;
		}
		if(bomnext!=index && bomnext+1>=t_sum1 && bomnext+1<=t_sum2)
		{
			if( max < fabs(buffer[ix].num - data))
				max = fabs(buffer[ix].num - data);
			bomnext = index;
			break;
		}
		t_sum1 = t_sum2;
	}
	return max;
}

void deal_pairs(vector<pairs> buffer, int n, int sum)
{
	int t_index = 0;
	int num = 0;
	int pre_num = getmax2(buffer, n, sum, t_index);
	int nums = 0;
	for(vector<pairs>::size_type ix = 0; ix != buffer.size(); ++ix)
	{
		//cout<<buffer[ix].num<<" "<<buffer[ix].nums<<endl;
		for(int i = 0; i<buffer[ix].nums; i++)
		{
			if(i==n+2 && buffer[ix].nums>= 2*n+3)
			{
				nums += buffer[ix].nums - 2*n - 2;
				t_index += buffer[ix].nums - 2*n - 2;
				i = buffer[ix].nums - n -1;
				continue;
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
		vector<pairs> buffer;
		int nums = 0;
		int num = 0;
		int sum = 0;
		while(cin>>num>>nums)
		{
			if(num == 0 && nums == 0)
				break;
			sum += nums;
			pairs data = {num, nums};
			buffer.push_back(data);
		}
		//debug_p_pairs(buffer, n);
		//debug_p_bitmap(buffer, n, sum);
		deal_pairs(buffer, n, sum);
		cout<<0<<" "<<0<<endl;

	}
	cout<<0<<endl;
	return 0;
}