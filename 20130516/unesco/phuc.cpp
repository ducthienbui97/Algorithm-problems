#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
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
using namespace std;

int n, m, s, f, d [100001], t [100001];
vector <pair <int, int> > adj [100001];


int main (int argc, char **argv)
{
	freopen ("UNESCO.INP", "r", stdin);
	freopen ("UNESCO.OUT", "w", stdout);
	scanf ("%d%d%d%d", &n, &m, &s, &f);
	
	while (m--)
	{
		int u, v, w; scanf ("%d%d%d", &u, &v, &w);
		
		adj [u].push_back (make_pair (v, w));
		adj [v].push_back (make_pair (u, w));
	}
	
	
	priority_queue <pair <int, int> > pq;
	
	d [s] = 2e9;
	pq.push (make_pair (d [s], s));
	
	while (pq.size ())
	{
		pair <int, int> tmp = pq.top (); pq.pop ();
		int u = tmp.second;
		
		if (u == f) break;
		if (d [u] == tmp.first)
			for (int i = 0; i < adj [u].size (); ++i)
			{
				int v = adj [u][i].first, w = adj [u][i].second;
				
				if (d [v] < min (d [u], w))
				{
					t [v] = u;
					d [v] = min (d [u], w);
					pq.push (make_pair (d [v], v));
				}
			}
	}
	
	if (d [f] == 0)
	{
		printf ("-1\n");
		return 0;
	}
	
	vector <int> path;
	
	printf ("%d\n", d [f]);
	
	while (f)
	{
		path.push_back (f);
		f = t [f];
	}
	
	printf ("%d\n", path.size ());
	
	for (int i = path.size (); i--;)
	{
		printf ("%d", path [i]);
		if (i) putchar (' ');
	}
	puts ("");
	
	return 0;
}
