/*
���⣺��n������ÿ������һ����ʼ��ÿ��λʱ����Ϲ����������������ʱ���Ϲ��ʻ���di�����ʲ����½���������ʱ���Ϲ��ʲ��䡣��n�������ų�һ�ŵģ��ӵ�һ������ʼÿ����λʱ�����ѡ������������һ�����ߣ���Щ·�ǵ���Ĳ��������ߡ�������ʱ��h��������ܵ��������㡣

��������������ö�پ���Ҫ��ǰ���ٸ������㣬��ô���ǿ����Ƚ�·�ϵ�ʱ�����ã�Ȼ����Ϊ���ǿ������⼸����֮��˲��ת�ƣ�ÿ����һ���Ϲ�����ߵĺ�ȥ�����ɡ�

*/

#include <iostream>
#include <stdio.h>
using namespace std;

const    int        maxn=26,maxh=16;

void    init();
void    work();
void    print();
void    make(int a,int time);

int        N,n,h,f[maxn],d[maxn],t[maxn-1],ans[maxn],ansf;
bool    p=false;

int main()
{
//    freopen("t.txt","r",stdin);
    N = 1;
    while (N--)
    {
        while (cin>>n&&n!=0)
        {
            init();
            work();
            print();
        }
    }
    return 0;
}

void init()
{
    int        i;
    
    cin>>h;
    h=h*12;
    ansf=-1;
    for (i=1;i<=n;i++)
        cin>>f[i];
    for (i=1;i<=n;i++)
        cin>>d[i];
    for (i=1;i<n;i++)
        cin>>t[i];
}

void work()
{
    int        i,time=0;

    t[0]=0;
    for (i=1;i<=n;i++)
    {
        time+=t[i-1];
        make(i,h-time);
    }
}

void print()
{
    int        i;

    if (p)
        cout<<endl;
    for (i=1;i<n;i++)
        cout<<ans[i]*5<<", ";
    cout<<ans[n]*5<<endl<<"Number of fish expected: "<<ansf<<endl;
    p=true;
}

void make(int a,int time)
{
    int        i,ls[maxn],max1,maxi,fish=0,ans1[maxn],j;

    memset(ans1,0,sizeof(ans1));
    for (i=1;i<=a;i++)
        ls[i]=f[i];
    while (time>0)
    {
        max1=-1;
        maxi=-1;
        for (i=1;i<=a;i++)
            if (ls[i]>max1)
            {
                max1=ls[i];
                maxi=i;
            }
        ans1[maxi]+=1;
        fish+=max1;
        ls[maxi]=0>ls[maxi]-d[maxi]?0:ls[maxi]-d[maxi];
        time--;
    }
    if (fish<ansf)
        return;
    if (fish>ansf)
    {
        for (i=1;i<=n;i++)
            ans[i]=ans1[i];    
        ansf=fish;
        return;
    }
    j=1;
    while (j<=n&&ans1[j]==ans[j])
        j++;
    if (ans1[j]>ans[j])
        for (i=1;i<=n;i++)
            ans[i]=ans1[i];
}