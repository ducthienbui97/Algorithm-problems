#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int p[100010],n,vs[100010],mx[100010];
vector<ii> a[100010];
vector<int> road;

void init(){for(int i=1;i<=n;i++) p[i]=i;}
int find(int i){return p[i]=(p[i]==i?i : find(p[i]));}
bool same(int i,int j){return find(i)==find(j);}
void uset(int i,int j){p[find(i)]=find(j);}

void dfs(int u){
	for(int i=0;i<(int)a[u].size();i++){
		ii v=a[u][i];
		if(!vs[v.first]){
			mx[v.first]=min(mx[u],v.second);
			vs[v.first]=u;
			dfs(v.first);
		}
	}
}

void path(int u){
	if(vs[u]!=-1) path(vs[u]);
	road.push_back(u);
}

int main()
{
	//freopen("a","r",stdin);
	freopen("UNESCO.INP","r",stdin);
	freopen("UNESCO.OUT","w",stdout);
	for(int i=0;i<100010;i++) mx[i]=1<<30;
	int s,f,u,v,w,m;
	vector<iii> ed;
	cin >> n >> m >> s >> f;
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		ed.push_back(iii(w,ii(u,v)));
	}
	init();sort(ed.rbegin(),ed.rend());
	for(int i=0;i<m;i++){
		iii z=ed[i];w=ed[i].first;
		u=z.second.first,v=z.second.second;
		if(!same(u,v)){
			uset(u,v);
			a[u].push_back(ii(v,w));
			a[v].push_back(ii(u,w));
		}
	}
	if(!same(f,s)) cout << "-1";
	else{
		vs[s]=-1;
		dfs(s);
		cout << mx[f] << endl;
		path(f);
		cout << road.size() << endl;
		for(int i=0;i<(int)road.size();i++) cout << road[i] << " ";
	}
	return 0;
}
