//http://acm.hdu.edu.cn/showproblem.php?pid=1026
#include <stdio.h>
#include <string.h>
#define N 101
char map[N][N];
int book[N][N];
int prt[N][N] ;
struct queue {
    int x,y;
};

struct queue qu[N*N*20] = {0};


int output2(int x, int y)
{
    int i, t, idx = prt[x][y] ;
    if (idx == -1) return 0 ;
    t = output2(qu[idx].x, qu[idx].y) ;
    printf ("%ds:(%d,%d)->(%d,%d)\n", ++t, qu[idx].x, qu[idx].y,x,y) ;
    if (map[x][y] != '.')
        for (i = 0 ; i < map[x][y]-'0' ; i++)
            printf ("%ds:FIGHT AT (%d,%d)\n", ++t, x, y) ;
    return t ;
}
int bfs(int m, int n)
{
    int head=0;
    int tail=1;
    
    book[0][0] = 0;
    qu[0].x = 0;
    qu[0].y = 0;
    
    
    int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int i, flag = 0;
 
    while(head<tail)
    {
        int x,y;
        for(i=0;i<4;i++)
        {
            x = qu[head].x + next[i][0];
            y = qu[head].y + next[i][1];
            //printf("%d %d %d %d\n",x,y,head,tail);
            if(x<0 || x>=m || y<0 || y>=n)
                continue;
            
            if(map[x][y]=='X')
                continue;
            

            int tt = book[qu[head].x][qu[head].y] + 1 ;
            if (map[x][y] != '.') tt += map[x][y]-'0' ;
            if (book[x][y] != -1 && book[x][y] <= tt) continue ;

            qu[tail].x = x;
            qu[tail].y = y;
            book[x][y] = tt;
            prt[x][y] = head;
            
            tail++;
            
        }

        head++;
        
    }
    
    if(book[m-1][n-1]!=-1)
    {
        //for(i=0;i<=tail;i++)
        //    printf("%d %d %d %d\n",i, qu[i].x, qu[i].y, qu[i].f);
        printf("It takes %d seconds to reach the target position, let me show you the way.\n", book[m-1][n-1]);
        output2(m-1,n-1);
    }
    else
    {
        printf("God please help our poor hero.\n");
    }
    printf("FINISH\n");
}


main()
{
    int m,n;
    while(scanf("%d %d\n", &m, &n)!=EOF)
    {
        memset(book, -1, sizeof(book));
        memset(prt, -1, sizeof(prt));
        memset(qu, 0, sizeof(qu));
        //printf("%d %d\n", m, n);
        int i,j;
        for(i=0;i<m;i++)
        {
            scanf ("%s", map[i]) ;
        }

        
        bfs(m,n);
        
    }
}