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
#define base 1000000007ll
#define MAX 1005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,ii> iiii;
const long long oo=1e16;
/*                                                          End of template                                                                */

int m,n,k,t;
long long grid[205][205];
int game[205][205];
long long f[205][205][100];
void bfs()
{
    int i,j,p;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            for(p=0; p<(1<<k); p++) f[i][j][p]=oo;
    if(game[1][1]!=-1) f[1][1][1<<game[1][1]]=grid[1][1];
    else f[1][1][0]=grid[1][1];
    priority_queue<iiii,vector<iiii>,greater<iiii> > q; q.push(iiii(ii(grid[1][1],game[1][1]!=-1 ? (1<<game[1][1]) : 0),ii(1,1)));
    while(!q.empty())
    {
        iiii x=q.top(); q.pop();
        int cx=x.second.first,cy=x.second.second,d=x.first.first,bit=x.first.second;
        for(i=1; i<=4; i++)
        {
            int a=cx,b=cy;
            if(i==1) a++; if(i==2) b++;
            if(i==3) a--; if(i==4) b--;
            if(a>=1 && b>=1 && a<=m && b<=n)
            {
                if(game[a][b]==-1)
                {
                    if(f[a][b][bit]>f[cx][cy][bit]+grid[a][b])
                    {
                        f[a][b][bit]=f[cx][cy][bit]+grid[a][b];
                        q.push(iiii(ii(f[a][b][bit],bit),ii(a,b)));
                    }
                }
                else if(f[a][b][bit|game[a][b]]>f[cx][cy][bit]+grid[a][b])
                {
                    f[a][b][bit|game[a][b]]=f[cx][cy][bit]+grid[a][b];
                    q.push(iiii(ii(f[a][b][bit|game[a][b]],bit|game[a][b]),ii(a,b)));
                }
            }
        }
    }
    long long ans=oo;
    for(i=0; i<=(1<<k); i++)
        if(__builtin_popcount(i)>=t) ans=min(ans,f[m][n][i]);
    cout<<ans;
}

int main()
{
    freopen("xyz.inp","r",stdin);
    freopen("xyz.out","w",stdout);
    int i,j,a,b;
    scanf("%d %d %d %d",&m,&n,&k,&t);
    memset(game,-1,sizeof(game));
    for(i=0; i<k; i++)
    {
        scanf("%d %d",&a,&b);
        game[a][b]=i;
    }
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++) cin>>grid[i][j];
    bfs();
    return 0;
}
