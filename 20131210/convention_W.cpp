#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<deque>
#include<map>
#include<set>
#define oo 1000000000
#define ooll 1ll<<50
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
                            /*                           END OF TEMPLATE                            */
//IOI 2014
int n,f[400005],par[25][200005],trace[400005],height[200005],mn[25][200005];
ii num[200005];
vector<int> event;
vector<ii> pos[400005];
map<int,int> code;
ii lca(int u,int v)
{
    for(int i=20; i>=0; i--)
        if(par[i][u]!=par[i][v]) u=par[i][u],v=par[i][v];
    return ii(u,v);
}
int MIN(int u,int v)
{
    if(min(u,v)==0) return max(u,v);
    return min(u,v);
}
int get(int u,int v)
{
    int res=oo;
    for(int i=20; i>=0; i--)
        if(height[par[i][u]]>=height[v]-1) res=MIN(res,mn[i][u]),u=par[i][u];
    return res;
}
int main()
{
    //freopen("convention.inp","r",stdin);
    //freopen("convention.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&num[i].first,&num[i].second);
        event.push_back(num[i].first);
        event.push_back(num[i].second);
    }
    sort(event.begin(),event.end());
    event.erase(unique(event.begin(),event.end()),event.end());
    for(int i=0; i<event.size(); i++) code[event[i]]=i+1;
    for(int i=1; i<=n; i++) pos[code[num[i].second]].push_back(ii(code[num[i].first],i));
    for(int i=1; i<=event.size(); i++)
    {
        f[i]=f[i-1];
        for(int j=0; j<pos[i].size(); j++)
        {
            ii x=pos[i][j];
            f[i]=max(f[i],f[x.first-1]+1);
        }
    }
    cout<<f[event.size()]<<endl;
    for(int i=1; i<=event.size(); i++)
    {
        if(f[i]==f[i-1]) trace[i]=trace[i-1];
        for(int j=0; j<pos[i].size(); j++)
        {
            ii x=pos[i][j];
            int u=trace[x.first-1];
            // try to add u -> x.second
            par[0][x.second]=u;
            mn[0][x.second]=x.second;
            for(int t=1; t<=20; t++)
            {
                par[t][x.second]=par[t-1][par[t-1][x.second]];
                mn[t][x.second]=MIN(mn[t-1][x.second],mn[t-1][par[t-1][x.second]]);
            }
            height[x.second]=height[u]+1;
            if(f[i]==f[x.first-1]+1)
            {
                if(!trace[i]) trace[i]=x.second;
                // compare x.second with trace[i]
                else if(height[x.second]==height[trace[i]])
                {
                    ii p=lca(x.second,trace[i]);
                    if(get(x.second,p.first)<get(trace[i],p.second)) trace[i]=x.second;
                }
            }
        }
    }
    int x=trace[event.size()];
    vector<int> ans;
    while(x) ans.push_back(x),x=par[0][x];
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
    return 0;
}
