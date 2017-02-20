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

#define oo 18446744073709551615LLU
#define PI acos(-1)

typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

#define shl(x) (1<<(x))
#define maxn 200 + 10
#define maxk 64 + 10

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
unsigned long long F [maxn][maxn][maxk];
int cost [maxn][maxn], favo [maxn][maxn];
int n, m, k, t;
typedef pair <unsigned long long, int> li;

bool check(ii a)
{
	return ( a. fi > 0 && a. fi <=n && a. se >0 && a. se <= m );
}

bool num(int s)
{
	int cnt=0;
	for (int i=0; i<k; i++)
		if ( s&shl(i) ) cnt++;
	if ( cnt == t ) return true;
	return false;
}

unsigned long long Dijkstra()
{
	typedef pair <li, ii> Index;
	priority_queue < Index, vector <Index> , greater <Index> > pq;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			for (int l=0; l<(shl(k)); l++)
				F[i][j][l] = oo;

	if ( favo [1][1] ) {
		F[1][1][1] = cost[1][1];
		pq. push(mp(mp(cost[1][1], shl(favo[1][1]-1)), mp(1, 1)));
	}
	else {
		F[1][1][0] = cost[1][1];
		pq. push(mp(mp(cost[1][1], 0), mp(1, 1)));
	}
	
	while (!pq. empty()) {
		Index u = pq. top(); pq. pop();
//		cout << "POP: cost: " << u.fi.fi << " State: " << u.fi.se << " locate: (" << u.se.fi << "," << u.se.se << ")" << endl;
		if ( u.se == ii(n, m) && num(u.fi.se) ) return u.fi.fi;
		if ( F[u.se.fi][u.se.se][u.fi.se] != u.fi.fi ) continue;
		for (int i=0; i<4; i++) {
			ii v (u.se.fi + dx[i], u.se.se + dy[i]);
			if ( check(v) ) {
				if ( favo [v.fi][v.se] && !(u.fi.se & shl(favo[v.fi][v.se]-1)) && 
				u.fi.fi + cost[v.fi][v.se] < F[v.fi][v.se][u.fi.se + shl(favo[v.fi][v.se]-1)] ) {
						
					F[v.fi][v.se][u.fi.se + shl(favo[v.fi][v.se]-1)] = u.fi.fi + cost[v.fi][v.se];
//					cout << "PUSH: cost: " << F[v.fi][v.se][u.fi.se + shl(favo[v.fi][v.se]-1)] << " state: " << u.fi.se + shl(favo[v.fi][v.se]-1) << " locate: (" << v.fi << "," << v.se << ")" << endl;
					pq. push(mp(mp(F[v.fi][v.se][u.fi.se + shl(favo[v.fi][v.se]-1)], u.fi.se + shl(favo[v.fi][v.se]-1)), v));
				}
				else if ( u.fi.fi + cost[v.fi][v.se] < F[v.fi][v.se][u.fi.se] ) {
					F[v.fi][v.se][u.fi.se] = u.fi.fi + cost[v.fi][v.se];
//					cout << "PUSH: cost: " << F[v.fi][v.se][u.fi.se] << " state: " << u.fi.se << " locate: (" << v.fi << "," << v.se << ")" << endl;
					pq. push(mp(mp(F[v.fi][v.se][u.fi.se], u.fi.se), v));
				}
			}
		}
//		cout << endl;
	}
	return -1;
}

int main()
{
    freopen("XYZ.INP","r",stdin);
    freopen("XYZ.OUT","w",stdout);
	cin >> n >> m >> k >> t;
	memset(favo, 0, sizeof favo);
	for (int i=1; i<=k; i++) {
		int a, b;
		cin >> a >> b;
		favo[a][b] = i;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> cost[i][j];
	cout << Dijkstra() << endl;
    return 0;
}
