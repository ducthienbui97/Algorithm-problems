#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int maxN = 100005;
const int inf = 1900000000;
int p[maxN][25],h[maxN],dmax[maxN][25],dmin[maxN][25];
bool visited[maxN];
typedef pair<int,int> ii;
vector<ii> G[maxN];
int Log=0;

void dfs(int u){
	visited[u]=true;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].first;
		int w=G[u][i].second;
		if(!visited[v]){
			h[v]=h[u]+1;
			p[v][0]=u;
			dmax[v][0]=w;
			dmin[v][0]=w;
			dfs(v);
		}
	}
}

ii LCA(int u,int v){
	int Min=inf,Max=-1;
	if(h[u]!=h[v]){
		if(h[u]<h[v]) swap(u,v);
		for(int i=Log;i>=0;i--){
			if(h[p[u][i]]>=h[v]){
				Max=max(Max,dmax[u][i]);
				Min=min(Min,dmin[u][i]);
				u=p[u][i];
			}
		}
	}
	if(u==v) return ii(Min,Max);
	if(u!=v){
		for(int i=Log;i>=0;i--){
			if(p[u][i]!=p[v][i]){
				Max=max(Max,max(dmax[u][i],dmax[v][i]));
				Min=min(Min,min(dmin[u][i],dmin[v][i]));
				u=p[u][i];
				v=p[v][i];
			}
		}
		Max=max(Max,max(dmax[u][0],dmax[v][0]));
		Min=min(Min,min(dmin[u][0],dmin[v][0]));
		return ii(Min,Max);
	}
}

int main(){
    freopen("traffic.inp","r",stdin);
    freopen("traffic.out","w",stdout);
	int n,k,u,v,w;
	scanf("%d",&n);
	do Log++; while((1<<Log)<n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back(ii(v,w));
		G[v].push_back(ii(u,w));
	}
	h[1]=1;
	dfs(1);
	for(int j=1;j<=Log;j++)
		for(int i=1;i<=n;i++){
			p[i][j]=p[p[i][j-1]][j-1];
			dmax[i][j]=max(dmax[i][j-1],dmax[p[i][j-1]][j-1]);
			dmin[i][j]=min(dmin[i][j-1],dmin[p[i][j-1]][j-1]);
		}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&u,&v);
		ii res=LCA(u,v);
		printf("%d %d\n",res.first==inf?0:res.first,res.second==-1?0:res.second);
	}
	return 0;
}
