#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<bitset>
#include<set>
#include<climits>
#include<deque>
#include<utility>
#include<functional>
#include<istream>
#include<ostream>
#include<memory>
#include<locale>
#include<cassert>
#include<iterator>
#define oo 1000000000
#define base 1000000007ll
#define MAX 1005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
/*                                                          End of template                                                                */

int grid[105][105],house[105][105];
int m,n,best=0,bestcount,cnt=0,total=0;

int absolute(int x)
{
    return x>=0 ? x: 0;
}

void bfs(ii start)
{
    int i,j,paint=0;
    house[start.first][start.second]=++cnt;
    queue<ii> q; q.push(start);
    while(!q.empty())
    {
        ii x=q.front(); q.pop();
        int cx=x.first,cy=x.second;
        for(i=1; i<=4; i++)
        {
            int a=cx,b=cy;
            if(i==1) a++; if(i==2) a--;
            if(i==3) b++; if(i==4) b--;
            paint+=absolute(grid[cx][cy]-grid[a][b]);
            if(a>=1 && b>=1 && a<=m && b<=n)
            {
                if(house[a][b]==-1 && grid[a][b]!=0)
                {
                    house[a][b]=cnt;
                    q.push(ii(a,b));
                }
            }
        }
    }
    if(best<paint)
    {
        best=paint;
        bestcount=cnt;
    }
    total+=paint;
}

int main()
{
    freopen("PAINTING.INP","r",stdin);
    freopen("PAINTING.OUT","w",stdout);
    int i,j,x;
    scanf("%d %d",&m,&n);
    memset(grid,0,sizeof(grid));
    memset(house,-1,sizeof(house));
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++) scanf("%d",&grid[i][j]);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(house[i][j]==-1 && grid[i][j]!=0) bfs(ii(i,j));
    printf("%d\n",cnt);
    printf("%d\n",total);
    printf("%d %d\n",bestcount,best);
    return 0;
}
