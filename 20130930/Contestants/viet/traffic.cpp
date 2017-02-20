#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#define MAX 100005
#define INF 10000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
/*                                                          End of template                                                                  */
int V;
vector<vii> G;
int par[20][MAX],Min[20][MAX],Max[20][MAX],Log[MAX],height[MAX];
void dfs(int u)
{
     int i;
     for(i=0; i<G[u].size(); i++)
     {
              ii v=G[u][i];
              if(v.first!=par[0][u])
              {
                              height[v.first]=height[u]+1;
                              par[0][v.first]=u;
                              Min[0][v.first]=Max[0][v.first]=v.second;
                              dfs(v.first);
              }
     }
}
void solve(int u,int v)
{
     int x,i,j,k,mn=INF,mx=-INF;
     if (height[u] < height[v]) swap(u,v);
           int l=height[u]-height[v];
           for(i=18; i>=0; i--)
           {
                x=par[i][u];
                if(x >= 0 && height[x] >= height[v])
                {
                         mn=min(mn,Min[i][u]);
                         mx=max(mx,Max[i][u]);
                         u = x;
                }
           }
     
     if (u != v)
     for(i=18; i>=0; i--)
     {
               if(par[i][u]!=par[i][v])
               {
                                       mn=min(mn,Min[i][u]);
                                       mx=max(mx,Max[i][u]);
                                       mn=min(mn,Min[i][v]);
                                       mx=max(mx,Max[i][v]);
                                       u=par[i][u];
                                       v=par[i][v];
               }
     }
     if(u!=v)
     {
             mn=min(mn,Min[0][u]);
             mx=max(mx,Max[0][u]);
             mn=min(mn,Min[0][v]);
             mx=max(mx,Max[0][v]);
             u=par[0][u];
             v=par[0][v];
     }
     printf("%d %d\n",mn,mx);
}
void init()
{
     memset(par,-1,sizeof(par));
     int i,j;
     Log[1]=0;
     for(i=2; i<=MAX; i++)
     {
              if(i==(1<<(Log[i-1]+1))) Log[i]=Log[i-1]+1;
              else Log[i]=Log[i-1];
     }
     scanf("%d",&V);
     G.assign(V,vii());
     for(i=1; i<V; i++)
     {
              int a,b,w;
              scanf("%d %d %d",&a,&b,&w);
              a--; b--;
              G[a].push_back(ii(b,w));
              G[b].push_back(ii(a,w));
     }
     height[0]=1;
     dfs(0);
     for(j=1; j<=Log[V]; j++)
     {
              for(i=0; i<V; i++)
              {
                       int x=par[j-1][i],mn=Min[j-1][i],mx=Max[j-1][i];
                       if(x>=0 && par[j-1][x]!=-1)
                       {
                               par[j][i]=par[j-1][x];
                               Min[j][i]=min(mn,Min[j-1][x]);
                               Max[j][i]=max(mx,Max[j-1][x]);
                       }
              }
     }
}
void execute()
{
     int i,j,k,n,q;
     init();
     scanf("%d",&q);
     for(i=1; i<=q; i++)
     {
              int a,b;
              scanf("%d %d",&a,&b);
              a--; b--;
              solve(a,b);
     }
}

int main()
{
    freopen("traffic.inp","r",stdin);
    freopen("traffic.out","w",stdout);
    execute();
    return 0;
}

