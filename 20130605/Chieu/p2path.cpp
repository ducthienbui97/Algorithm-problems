#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <utility>
#include <complex>
#define elif else if
#define X real()
#define Y imag() 
using namespace std;    
typedef  pair<int,int> pii;
const int Maxn=203;
int n;
int ans;
vector <pii> eg;
vector <int> d[Maxn];
int m[Maxn];
queue<pii> bfs;
void dfs(int x,int y){
	bfs.push(pii(0,1));
	int a,b,j;
	int ans1=0,ans2=0;
	int last=0;
	int dx=0;
	memset(m,-1,sizeof m);
	m[1]=0;
	while(!bfs.empty()){
		a=bfs.front().first;
		b=bfs.front().second;
		bfs.pop();
		if(a>last) {
			last=a;
			dx=b;
		}		
		for(int i=0;i<(int) d[b].size();i++){
			if(b==x&&d[b][i]==y) continue;
			if(d[b][i]==x&&b==y) continue;
			if(m[d[b][i]]==-1) {
				m[d[b][i]]=0;
				bfs.push(pii(a+1,d[b][i]));
			}
		}
	}
	bfs.push(pii(0,dx));
	while(!bfs.empty()){
		a=bfs.front().first;
		b=bfs.front().second;
		bfs.pop();
		if(a>ans1) ans1=a;
		for(int i=0;i<(int) d[b].size();i++){
			if(b==x&&d[b][i]==y) continue;
			if(d[b][i]==x&&b==y) continue;
			if(m[d[b][i]]==0) {
				m[d[b][i]]=1;
				bfs.push(pii(a+1,d[b][i]));
			}
		}
	}
	last=0;
	j=0;
	for(int i=1;i<=n;i++)
	if(m[i]==-1) {
		j=i;
		break;
	}
	bfs.push(pii(0,j));
	m[j]=0;
	dx=0;
	while(!bfs.empty()){
		a=bfs.front().first;
		b=bfs.front().second;
		bfs.pop();
		if(a>last) {
			last=a;
			dx=b;
		}		
		for(int i=0;i<(int) d[b].size();i++){
			if(b==x&&d[b][i]==y) continue;
			if(d[b][i]==x&&b==y) continue;
			if(m[d[b][i]]==-1) {
				m[d[b][i]]=0;
				bfs.push(pii(a+1,d[b][i]));
			}
		}
	}
	bfs.push(pii(0,dx));
	while(!bfs.empty()){
		a=bfs.front().first;
		b=bfs.front().second;
		bfs.pop();
		if(a>ans2) ans2=a;
		for(int i=0;i<(int) d[b].size();i++){
			if(b==x&&d[b][i]==y) continue;
			if(d[b][i]==x&&b==y) continue;
			if(m[d[b][i]]==0) {
				m[d[b][i]]=1;
				bfs.push(pii(a+1,d[b][i]));
			}
		}
	}
	ans=max(ans,(ans1*ans2));
}
main(){
	//freopen("p2path.inp","r",stdin);
	//freopen("p2path.out","w",stdout);
	int x,y;
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		d[x].push_back(y);
		d[y].push_back(x);
		eg.push_back(make_pair(x,y));
	}
	for(int i=0;i<(int) eg.size();i++){
		dfs(eg[i].first,eg[i].second);
	}
	cout<<ans;
}
