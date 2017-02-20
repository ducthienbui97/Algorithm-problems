#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct canh{
	int den,w;
};
struct ptheap{
	int ind,gt;
	bool operator<(const ptheap& d2) const {
		return gt<d2.gt;
	}
};

int n,m,u,v,D[10000];
vector<canh> dinh[10000];
priority_queue<ptheap> pq;

void dijkstra(){
	ptheap pt,pt2;
	pt.ind=u;
	pt.gt=0;
	D[u]=0;
	pq.push(pt);
	while(!pq.empty()){
		pt=pq.top();
		pt.gt=0-pt.gt;
		pq.pop();
		for(int i=0;i<dinh[pt.ind].size();i++){
			if (D[dinh[pt.ind][i].den]>max(D[pt.ind],dinh[pt.ind][i].w)){
				D[dinh[pt.ind][i].den]=max(D[pt.ind],dinh[pt.ind][i].w);
				pt2.ind=dinh[pt.ind][i].den;
				pt2.gt=0-D[dinh[pt.ind][i].den];
				pq.push(pt2);
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
	for(int i=0;i<n;i++) D[i]=2000000000;
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
