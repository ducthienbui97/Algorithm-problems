#include <cstdio>
#include <queue>
#define MAX 6000
int a[MAX][MAX];
int m[MAX][MAX];
int r,c;
int dx[]= {1,0,-1,0,1,1,-1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
void dfs(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c)
    {
        m[x][y]=1;
        for(int i=0; i<8; i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(m[xx][yy]==0&&a[xx][yy]!=0) dfs(xx,yy);
        }
    }
}

main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    int grass=0;
    scanf("%d %d",&r,&c);
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
        {
            scanf("%d",&a[i][j]);
        }
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
        {
            if(m[i][j]==0&&a[i][j]!=0) {grass++;dfs(i,j);}
        }
    printf("%d",grass);
}
/*
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
*/
