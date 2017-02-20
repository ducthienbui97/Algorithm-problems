#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define elif else if
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
int const r=1e9+7;
bool vs[111111],b[111111];
vector <int> d[111111];
int dx[111111];
void dfss(int i)
{
    if(!b[i])
    {
        b[i]=true;
        for(int j=0;j<d[i].size();j++)
        dfss(d[i][j]);
    }
}
long long int res;
void dfs(int c,int n,int k)
{
     if(!vs[n])
    {
        dx[n]=k;
        vs[n]=true;
        for(int j=0;j<d[n].size();j++)
        if(vs[d[n][j]]&&d[n][j]!=c)
        {
            if(dx[d[n][j]]<dx[n])
            res=((res%r)*((abs(dx[d[n][j]]-dx[n])+1)%r))%r;
        }
        else dfs(n,d[n][j],k+1);
    }
}
main()
{
    int n,m;
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfss(1);
    bool check=false;
    for(int i=1;i<=n;i++)
    if(!b[i]) check=true;
    res=1;
    if(check) printf("0");
    else
    {
        dfs(0,1,1);
        printf("%lld",res);
    }
}
