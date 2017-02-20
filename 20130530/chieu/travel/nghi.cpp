#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define fo(i,a,b) for(int i=a,_b=b;i<=_b;i++)

vector<ii> a[2012];
int check[2012],t[10];
int d[2012],dist[10][10];
int f[1<<23][10];

void dijkstra(int s){
	for(int i=0;i<2012;i++) d[i]=1<<30;
	priority_queue< iii,vector<iii>,greater<iii> > pq;
	pq.push(iii(ii(0,s),1));d[s]=0;
	while(!pq.empty()){
		ii u=pq.top().first;int x=pq.top().second;pq.pop();
		for(int i=0;i<(int)a[u.second].size();i++){
			ii v=a[u.second][i];
			if(d[v.first]>d[u.second]+v.second){
				d[v.first]=d[u.second]+v.second;
				d[v.first]-=d[v.first]/10.0;
				if(check[v.first]){
					dist[check[s]][check[v.first]]=dist[check[v.first]][check[s]]=d[v.first];
					pq.push(iii(ii(d[v.first],v.first),x+1));
				}
				else pq.push(iii(ii(d[v.first],v.first),x));
			}
		}
	}
}

int main()
{
	freopen("TRAVEL.INP","r",stdin);
	freopen("TRAVEL.OUT","w",stdout);
	int m,n,k,u,v,c1,c2;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> u >> v >> c1 >> c2;
		a[u].push_back(ii(v,c1));
		a[v].push_back(ii(u,c2));
	}
	int x;
	for(int i=1;i<=k;i++){cin >> x;check[x]=i;t[i]=x;}
	for(int i=1;i<=k;i++){dijkstra(t[i]);}
	
	fo(s,0,(1<<k)-1)
		fo(i,1,k)
			f[s][i]=1<<30;
	fo(i,1,k) f[1<<(i-1)][i]=0;
	
	fo(s,0,(1<<k)-1)
		fo(u,1,k)
		if((s&(1<<(u-1)))>0)
			fo(v,1,k)
			if( u!=v && (s&(1<<(v-1)))>0 )
				f[s][u]=min(f[s][u],f[s-(1<<(u-1))][v]+dist[v][u]);
				
	int rape=1<<30;
	fo(i,1,k) {rape=min(rape,f[(1<<k)-1][i]);}
	printf("%d",rape);
	
 	return 0;
}

