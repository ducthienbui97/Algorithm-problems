#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vi;

vi a[2012];
int clr[2012],n,m,cnt;
int check=0;

void dfs(int u) {
	if(check) return;
	for(int i=0;i<(int)a[u].size();i++){
		int v=a[u][i];
		if(!clr[v]){
			clr[v]=clr[u]+1;
			dfs(v);
		}
		else if(clr[u]%2==clr[v]%2) check=1;
	}
}

int main()
{
	freopen("BUGLIFE.INP","r",stdin);
	freopen("BUGLIFE.OUT","w",stdout);
	int u,v,tc;
	cin >> tc;
	for(int z=1;z<=tc;z++) {
		cin >> n >> m;
		cnt=1;check=0;
		for(int i=0;i<=n+1;i++) a[i].clear(),clr[i]=0;
		for(int i=0;i<m;i++){
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=1;i<=n;i++) if(!clr[i]) clr[i]=1,dfs(i);
		cout << "Scenario #" << z << ":" << endl;
		if(check) cout << "Suspicious bugs found!";
		else cout << "No suspicious bugs found!";
		cout << endl;
	}
	return 0;
}

