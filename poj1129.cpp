/*
题意：给定无向图，对点着色，使得相邻的结点颜色不同。

直接搜索，没有用四色原理，用四色原理也是暴力，没有什么影响。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define M 26

int n, ans, color[M]; 
bool map[M][M], isFind;

bool ok(int x, int c) {   //判断是否存在相邻节点颜色相同
     for (int i = 0; i < n; i++)
        if (map[x][i] && c == color[i])
            return false;
     return true;
}

void DFS(int id, int total) {   //当前搜索到下标为id的节点，此时总共用的色彩数为total
     if (isFind) return;
     if (id >= n) { isFind = true; return; }  //当所有节点都被着色后，返回

     for (int i = 1; i <= total; i++) {
         if (ok(id, i)) {
            color[id] = i;
            DFS(id+1, total);
            color[id] = 0;
         }
     }
     if (!isFind) {    //当用total种颜色无法完成时，则增加一种颜色进行着色
        ans++;
        DFS(id, total+1);
     }
}

int main()
{
    int i, j;
    char s[M];

    while (scanf ("%d", &n) && n) {
          getchar();
          memset (map, false, sizeof (map));
          memset (color, 0, sizeof (color));
          for (i = 0; i < n; i++) {
               gets(s);
               for (j = 2; s[j] != '\0'; j++)
                   map[s[0]-'A'][s[j]-'A'] = true;
          }
          isFind = false;
          ans = 1;
          DFS(0, 1);
          if (ans == 1)
              printf ("1 channel needed.\n");
          else printf ("%d channels needed.\n", ans);
    }
    return 0;
}
