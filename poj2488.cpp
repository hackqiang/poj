#include<stdio.h>
#include<string.h>
int cood[8][2]= {-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int map[27][27];
int vis[27][27];
int len;
int x,y;
bool flag;
struct Node
{
    int x,y;

} node[1000000];
void DFS(int a,int b)
{
    if(len==x*y)
    {
        flag=true;
        return ;
    }
    for(int c=0; c<8; c++)
    {
        int xa=a+cood[c][0];
        int ya=b+cood[c][1];
        if(xa>0&&xa<=x&&ya>0&&ya<=y&&vis[xa][ya]!=1)
        {

            node[len].x=xa;
            node[len].y=ya;
            vis[xa][ya]=1;
            ++len;
            DFS(xa,ya);
            if(len==x*y)
            {
                flag=true;
                return ;
            }
            --len;
            vis[xa][ya]=0;
        }
    }
}
int main()
{
    int test;
    int i,j;
    scanf("%d",&test);
    for(j=1; j<=test; j++)
    {
        flag=false;
        len=0;
        memset(node,0,sizeof(node));
        memset(vis,0,sizeof(vis));
        node[0].x=1;
        node[0].y=1;
        vis[1][1]=1;
        scanf("%d%d",&y,&x);
        ++len;
        DFS(1,1);
        printf("Scenario #%d:\n",j);
        if(flag==false)
        {
            printf("impossible\n\n");
            continue;
        }
        for(i=0; i<len; i++)
        {
            printf("%c%d",(node[i].x-1)+'A',node[i].y);
        }
        printf("\n\n");
    }
    return 0;
}
