#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>
#include <cstring>
#include <climits>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int Maxn=5010;
bool vs[Maxn][Maxn];
int n,m;
int h[Maxn][Maxn];
queue<pair<int,int> > bfs;
int xi[] ={-1,-1,-1,0,0,1,1,1};
int yi[] ={-1,0,1,-1,1,0,-1,1};
void dfs(int i,int j)
{
    int x,y;
    bfs.push(make_pair(i,j));
    while(!bfs.empty())
    {
        x=bfs.front().first;
        y=bfs.front().second;
        bfs.pop();
        if(!vs[x][y])
        {
            vs[x][y]=true;
            for(int l=0; l<8; l++)
            {
                if(!vs[x+xi[l]][y+yi[l]]&&h[x+xi[l]][y+yi[l]]>0)
                    if(x+xi[l]>0&&x+xi[l]<=n&&y+yi[l]>0&&y+yi[l]<=m)
                        bfs.push(make_pair(x+xi[l],y+yi[l]));
            }
        }
    }
}

main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&h[i][j]);
        }
    int ck=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!vs[i][j]&&h[i][j]>0) ck++,dfs(i,j);
    printf("%d",ck);
}
