#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cmath>
using namespace std;
queue<int> qu;
int m,n,p,a,dem=0;
int dd[10000][10000];
void bfs(int i)
{
    qu.push(i);
	while(!qu.empty())
	{
		int u = qu.front();
		qu.pop();
		for(int j=u-1; j>=1; j--)
			if(dd[u][j]==1)
			{
				if(j==1)dem++;
                else qu.push(j);
			}
	}
	printf("%d\n",dem);
}
int main()
{
    freopen("2.inp","r",stdin);
    freopen("2.out","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    dd[1][1]=0;
    while(scanf("%d%d",&x,&y)==2 && x!=0 && y!=0)
    {
        dd[x][y]=1;
        dd[y][x]=1;
    }
    bfs(n);
}
