/*

http://blog.csdn.net/lyy289065406/article/details/6648102

有各种不同面值的货币，每种面值的货币有不同的数量，请找出利用这些货币可以凑成的最接近且小于等于给定的数字cash的金额。
多重背包问题，第i种面额d[i]有 n[i]+1种选择方案

可以转化为01背包问题处理

转化的大概思路就是把 每种面值乘以其不同的个数，把得到的不同金额作为一件新的独一无二的货币，但是这样存在两个问题，一是 d[i]*ki 可能等于 d[j]*kj  ，其中ki ∈n[i]，kj∈n[j]，二是这样做一定TLE超时（前人经验O(∩_∩)O哈哈~我就不重滔覆辙呐）

解题思路：

首先解决存储问题，cash上限实在太大了..10W，推荐用new，最后记得delete就是了，不然就算AC掉，Memory也会很大= =

说到空间的申请，说点题外话，这题不像POJ1837那么BT（做过1837的同学就知道了…1837连申请动态空间都很困难，因为空间的动态值是由3个变量的最大值决定的= =有时间浪费在找最大值，宁愿申请静态空间,反正才1W）
*/

//Memory Time 
//1052K  47MS 

#include<iostream>
using namespace std;

int main(int i,int j)
{
	int N;   //物品种数（面额种数）	
	int cash;  //背包容量（最大可取金额）
	while(cin>>cash>>N)
	{
		/*Input*/

		int* n=new int[N+1];  //n[i]第i种物品的个数（第i种面额的数量）
		int* w=new int[N+1];  //w[i]第i种物品的价值（第i种面额的价值）
		int* c=new int[N+1];  //c[i]第i种物品的体积（第i种面额消耗的价值）
		int* dp=new int[cash+1];  //dp[j]记录的是 当前最接近状态j且<=j的值，dp值会累积
		int* count=new int[cash+1];//计数器，限制某种物品（面额）的选取个数

		for(i=1;i<=N;i++)
		{
			cin>>n[i]>>w[i];
			c[i]=w[i];    //本题的单个物品的“体积”等于其“价值”
		}
		
		/*Initial*/

		memset(dp,0,4*(cash+1));  //由于dp申请的是动态内存，用sizeof计算长度会出错
		                          //这里要用 类型大小*个数,这里为 int*(cash+1) , int大小为4

		/*DP*/
		
		for(i=1;i<=N;i++)
		{
			memset(count,0,4*(cash+1));  //每更换一次面额，计数器清零
			for(j=w[i];j<=cash;j++)      //对于第i种货币，其面额d[i]~cash间任一个状态都可能发生
				if(dp[j]<dp[j-c[i]]+w[i] && count[j-c[i]]<n[i]) //count[j-c[i]]<n[i]
				{                                               //取某种面额前，必须保证这次操作之前所取该种面额的次数小于n[i]
					dp[j] = dp[j-c[i]]+w[i];    //选取第i个物品后，背包容量（允许取的最大金额）减少c[i]
					count[j]=count[j-c[i]]+1;   //对于当前状态j，第i种面额被抽了count[j]次
				}
		}

		/*Output*/
		
		cout<<dp[cash]<<endl;

		/*Release Space*/

		delete n;
		delete w;
		delete c;
		delete dp;
		delete count;
	}
	
	return 0;
}