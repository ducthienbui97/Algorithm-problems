#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>
#define MP(a,b) make_pair(a,b)
#define st first
#define nd second 
#define maxl 2000000000 
#define maxn 10000 
using namespace std;
struct canh{
	int den,w;
};

int n,m,u,v,D[maxn];
vector<canh> dinh[maxn];
set<pair<int,int> > h;

void dijkstra(){
	pair<int,int> pt,pt2;
	h.insert(MP(0,u));
	D[u]=0;
	int u1,v1,w;
	while(!h.empty()){
		pt=*h.begin();
		h.erase(h.begin());
		u1=pt.second;
		for(int i=0;i<dinh[u1].size();i++){
			v1=dinh[u1][i].den;
			w=dinh[u1][i].w;
			if (D[v1]>max(D[u1],w)){
				if (D[v1]!=maxl){
					h.erase(h.find(MP(D[v1],v1)));
				}
				D[v1]=max(D[u1],w);
				pt2=MP(D[v1],v1);
				h.insert(pt2);
			}
		}
	}
	cout<<D[v];
}

int main(){
	//freopen("MINIMAX.IN","r",stdin);
	//freopen("MINIMAX.OUT","w",stdout);
	cin>>n>>m;
	cin>>u>>v;
	u--;v--;
	int a,b,w;
	canh c;
	for(int i=0;i<n;i++) D[i]=maxl;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&w);
		a--;b--;
		c.w=w;
		c.den=b;
		dinh[a].push_back(c);
		c.den=a;
		dinh[b].push_back(c);
	}
	dijkstra();
	return 0;
}
