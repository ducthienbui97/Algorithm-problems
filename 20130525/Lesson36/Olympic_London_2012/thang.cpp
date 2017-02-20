#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define For(i,a,b) for (int i=(int)a, _b=(int)b; i<=_b; i++)
#define st first
#define nd second
#define mp make_pair
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef pair <int, ii> iii;
vector <vii> list;
int d[2][50010], n, m;
int dijkstra (int s, int f) {
	priority_queue <iii, vector <iii>, greater <iii> > pq;
	d[1][s] = 0;
	pq.push (mp (0, ii (s, 1)));
	
	while (!pq.empty()) {
		iii u = pq.top(); pq.pop();
		For (i, 0, list[u.nd.st].size() - 1) {
			ii v = list[u.nd.st][i];
			int t = u.nd.nd;
			if (t == 1) {
				if (d[1][v.st] > u.st + v.nd) {
					d[1][v.st] = u.st + v.nd;
					pq.push (mp (d[1][v.st], ii (v.st, 1)));
				}
				if (d[0][v.st] > u.st) {
					d[0][v.st] = u.st;
					pq.push (mp (d[0][v.st], ii (v.st, 0)));
				}
			}
			else if (d[0][v.st] > u.st + v.nd) {
					d[0][v.st] = u.st + v.nd;
					pq.push (mp (d[0][v.st], ii (v.st, 0)));
				}
		}
	}
	return min (d[0][f], d[1][f]);
}
void set (int n) {
	list.assign (n, vii());
	For (i, 0, 1)
		For (j, 0, n)
			d[i][j] = INT_MAX;
}
int main() {
	freopen ("Olympic_London_2012.inp", "r", stdin);
	freopen ("Olympic_London_2012.out", "w", stdout);
	
	int t1, t2, t3, s, f;
	scanf ("%d %d %d %d", &n, &m, &s, &f); set (n); s--; f--;
	For (i, 1, m) {
		scanf ("%d %d %d", &t1, &t2, &t3); t1--; t2--;
		list[t1].push_back (ii (t2, t3));
		list[t2].push_back (ii (t1, t3));
	}
	cout << dijkstra (s, f) << endl;
	return 0;
}
