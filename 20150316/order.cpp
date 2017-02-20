#include<stdio.h>
#include<vector>
#define M 2500
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int n,m;
int INF = 1e9;
struct edge{
	int u,v,capa,flow;
	void make(int _u,int _v,int _capa,int _flow){
		u = _u;v = _v ; capa = _capa ; flow = _flow;
	}
};
struct max_Flow{
	vector<int> V[M];
	vector<edge> E;
	int d[M];
	int s,t;
	int ptr[M];
	void init(int _s,int _t){
		for(int i =  0 ; i <= n+m+1 ; i++)	V[i].clear();
		E.clear();
		s =_s;
		t = _t;
	}
	void add_edge(int u,int v,int capa,int flow){
		edge curr;
		curr.make(u,v,capa,0);
		V[u].push_back(E.size()) ; E.push_back(curr);
		curr.make(v,u,0,0);
		V[v].push_back(E.size()) ; E.push_back(curr);
	}
	int bfs(int s,int t){
		queue<int> qq;
		for(int i = 0 ; i <= n + m + 1 ; i++)
			d[i] = -1;
		d[s] = 0;
		qq.push(s);
		while(!qq.empty()){
			int u = qq.front();
			qq.pop();
			for(int i = 0 ; i < V[u].size();i++){
				int id = V[u][i];
				if(E[id].capa > E[id].flow && d[E[id].v] == -1){
					d[E[id].v] = d[u] + 1;
					qq.push(E[id].v);
				}
			}
		}
		return (d[t]!=-1);
	}
	int dfs(int u,int t,int flow){
		if( u == t ) return flow;
		for(;ptr[u] < V[u].size() ; ptr[u]++){
			int id = V[u][ptr[u]];
			if(d[E[id].v] == d[u] + 1 && E[id].flow < E[id].capa){
				int pushed = dfs(E[id].v,t,min(flow,E[id].capa-E[id].flow));
				if(pushed > 0) {
					E[id].flow+=pushed;
					E[id^1].flow-=pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	int maxFlow(){
		int flow = 0;
		while(bfs(s,t)){
			memset(ptr,0,sizeof ptr);
			while(1){
				int inc = dfs(s,t,INF);
				flow+=inc;
				if(inc == 0) break;
			}
		}
		return flow;
	}
};
max_Flow MF;
int tot ;
void solve(){
	tot = 0;
	scanf("%d %d",&m,&n);
	MF.init(0,m+n+1);
	for(int i = 1 ; i <= m ; i++){
		int pi,wi;
		scanf("%d %d",&pi,&wi);
		tot+=pi;
		MF.add_edge(0,i,pi,0);
		for(int j = 1 ; j <= wi ; j++){
            int x,r;
            scanf("%d %d",&x,&r);
            MF.add_edge(i , m + x , r , 0);
		}
	}
	for(int i = 1 ; i <= n ; i++){
		int ci;
		scanf("%d",&ci);
		MF.add_edge(m+i,m+n+1,ci,0);
	}
	printf("%d\n",tot-MF.maxFlow());
}
main(){
	//freopen("test.inp","r",stdin);
	solve();
}
