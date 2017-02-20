#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define rp(i,n) for(int i=0;i<(n);i++)
#define rd(i,n) for(int i=(n)-1;i>=0;i--)
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) x.size()

#define oo 2147483647
#define PI acos(-1)

typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

#define maxn 50000 + 10
int F[maxn][2 + 10];
int V, E;
vector <ii> Adlist [maxn];
typedef pair <int, ii> iii;

int Dijkstra(int s, int f)
{
	priority_queue < iii, vector <iii> , greater <iii> > pq;
	for (int i=1; i<=V; i++)
		F[i][1] = F[i][0] = oo;
	F[s][1] = 0;
	pq. push(mp(0, ii(1, s)));
	while (!pq. empty()) {
		iii u = pq. top(); pq. pop();
		if ( u.se.se == f ) return u.fi;
		if ( F[u.se.se][u.se.fi] != u.fi ) continue;
		for (int i=0; i<Adlist[u.se.se]. size(); i++) {
			ii v = Adlist[u.se.se][i];
			if ( v.se + u.fi < F[v.fi][u.se.fi] ) {
				F[v.fi][u.se.fi] = v.se + u.fi;
				pq. push(mp(v.se + u.fi, ii(u.se.fi,v.fi)));
			}
			if ( u.se.fi > 0 && u.fi < F[v.fi][0] ) {
				F[v.fi][0] = u.fi;
				pq. push(mp(u.fi, ii(0, v.fi)));
			}
		}
	}
	return -1;
}

int main()
{
    freopen("Olympic_London_2012.inp","r",stdin);
    freopen("Olympic_London_2012.out","w",stdout);
	int s, f;
	cin >> V >> E >> s >> f;
	for (int i=1; i<=V; i++) Adlist[i]. clear();
	for (int i=1; i<=E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Adlist[a]. pb(ii(b, c));
		Adlist[b]. pb(ii(a, c));
	}
	cout << Dijkstra(s, f) << endl;
    return 0;
}
