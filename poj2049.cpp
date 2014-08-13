/*
题目大意：有一个迷宫，在迷宫中有墙与门
有m道墙，每一道墙表示为(x,y,d,t）
x,y表示墙的起始坐标
d为0即向右t个单位，都是墙
d为1即向上t个单位，都是墙
有n道门，每一道门表示为(x,y,d)
x,y表示门的起始坐标
d为0即向右一个单位表示门
d为1即向上一个单位表示门
再给出你起点的位置(f1,f2)，并保证这个点的位置不会再墙或者门中，为起点到(0,0)最少要穿过多少条门

注意：在迷宫中不只有门和墙，还有空地，因为理解错题目意思WA了一上午。

 

 


解题思路：调试的我有点头晕.
将坐标系看成网格，在这里我以每个格子的左下点为基点，那么坐标对应网格
坐标(0,0)的网格为(1,1)
坐标(1,1)的网格为(2,2)
坐标(1,2)的网格为(2,3)
...
依次类推

我再定义xa[i][j]代表网格(i,j)的上边的值
ya[i][j]代表网格(i,j)的右边的值
值分为三种，空地，墙，门
空地为0，墙为INF，门为1
首先全赋值为空地
然后根据输入来赋值
这样就便于搜索了
这里要注意的是要全部搜索完，因为要穿过最少的门，用优先队列搞定
还有当在迷宫外面时，直接输出0,这个不看讨论版真会WA到死
因为迷宫可能在[1,199]但是目标人物所在坐标可能超出这个范围
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAXV 210
#define INF 1<<29
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

#define EMPTY 0
#define DOOR 1
#define WALL INF 

int xa[MAXV][MAXV],ya[MAXV][MAXV];
int dis[MAXV][MAXV];
int dt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int xmax,ymax;

bool pd(int x,int y){
	if(x>0 && x<=xmax && y<=ymax && y>0) return 1;
	return 0;
}

int getvalue(int x,int y,int i){
	if(i==0) return ya[x-1][y];
	if(i==1) return ya[x][y];
	if(i==2) return xa[x][y-1];
	return xa[x][y];
}

int bfs(int tx,int ty){
	int i,j,vx,vy,dx,dy,tmp;
	queue <int>q;

	for(i=1;i<=ymax;i++){
		for(j=1;j<=xmax;j++)
			dis[i][j]=INF;
	}
	dis[1][1]=0;
	q.push(1);
	q.push(1);
	while(!q.empty()){
		vx=q.front();q.pop();
		vy=q.front();q.pop();

		for(i=0;i<4;i++){
			dx=vx+dt[i][0];
			dy=vy+dt[i][1];
			tmp=getvalue(vx,vy,i);
			if(pd(dx,dy) && dis[dx][dy]>dis[vx][vy]+tmp){
				dis[dx][dy]=dis[vx][vy]+tmp;
				q.push(dx);
				q.push(dy);
			}
		}
	}
	return (dis[tx][ty]==INF?-1:dis[tx][ty]);
}

int main(){
	int n,m,i,j;
	int x,y,d,t;
	double sx,sy;
	while(scanf("%d%d",&m,&n)){
		if(m==-1 && n==-1) break;

		ymax=xmax=-1;
		memset(xa,EMPTY,sizeof(xa));
		memset(ya,EMPTY,sizeof(ya));
		for(i=0;i<m;i++){
			scanf("%d%d%d%d",&x,&y,&d,&t);
			if(d){
				for(j=0;j<t;j++) ya[x][y+j+1]=WALL;
				ymax=max(y+t+1,ymax);
				xmax=max(x+1,xmax);
			}else{
				for(j=0;j<t;j++) xa[x+j+1][y]=WALL;
				ymax=max(y+1,ymax);
				xmax=max(x+t+1,xmax);
			}
		}

		for(i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&d);
			if(d) ya[x][y+1]=DOOR;
			else xa[x+1][y]=DOOR;
		}

		scanf("%lf%lf",&sx,&sy);
		if(!(sx>=1 && sx<=199 && sy>=1 && sy<=199)) printf("0\n");
		else printf("%d\n",bfs((int)sx+1,(int)sy+1));
	}
	return 0;
}