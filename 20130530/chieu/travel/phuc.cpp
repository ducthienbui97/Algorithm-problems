#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
using namespace std;

vector <pair <int, int> > adj [2001];
int n, m, k, d [2001][128], idx [2001];

int dijk ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < (1 << k); ++j)
			d [i][j] = 1e9;
	priority_queue <pair <int, pair <int, int> > > pq;
	
	memset (idx, -1, sizeof idx);
	for (int i = 0; i < k; ++i)
	{
		int x; scanf ("%d", &x);
		idx [x] = i;
		pq.push (make_pair (d [x][1 << i] = 0, make_pair (x, 1 << i)));
	}
	
	while (pq.size ())
	{
		pair <int, pair <int, int> > tmp = pq.top (); pq.pop ();
		int u = tmp.second.first, mask = tmp.second.second;
		if (mask == (1 << k) - 1) return -tmp.first;
		if (-tmp.first == d [u][mask])
			for (int i = 0; i < adj [u].size (); ++i)
			{
				int v = adj [u][i].first, mask1 = (idx [v] != -1 ? (mask | (1 << idx [v])) : mask);
				int w = (10 - (int) __builtin_popcount (mask1)) * adj [u][i].second / 10;
				if (d [v][mask1] > d [u][mask] + w)
				{
					d [v][mask1] = d [u][mask] + w;
					pq.push (make_pair (-d [v][mask1], make_pair (v, mask1)));
				}
			}
	}
	return -1;
}

int main (int argc, char **argv)
{
	freopen ("TRAVEL.INP", "r", stdin);
	freopen ("TRAVEL.OUT", "w", stdout);
	
	scanf ("%d%d%d", &n, &m, &k);
	
	while (m--)
	{
		int u, v, w, p; scanf ("%d%d%d%d", &u, &v, &w, &p);
		adj [u].push_back (make_pair (v, w));
		adj [v].push_back (make_pair (u, p));
	}
	
	printf ("%d\n", dijk ());
	
	return 0;
}
