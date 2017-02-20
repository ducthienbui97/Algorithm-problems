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

int n, m, s, f, d [50001][2];

vector <pair <int, int> > adj [50001];

int main (int argc, char **argv)
{
	#ifndef _
		freopen ("Olympic_London_2012.inp", "r", stdin);
		freopen ("Olympic_London_2012.out", "w", stdout);
	#endif
	cin >> n >> m >> s >> f;
	
	while (m--)
	{
		int u, v, w; scanf ("%d%d%d", &u, &v, &w);
		adj [u].push_back (make_pair (v, w));
		adj [v].push_back (make_pair (u, w));
	}
	
	for (int i = 1; i <= n; ++i)
		d [i][0] = d [i][1] = 1e9;
	
	set <pair <int, pair <int, int> > > st;
	st.insert (make_pair (d [s][0] = 0, make_pair (s, 0)));
	
	while (st.size ())
	{
		pair <int, pair <int, int> > tmp = *st.begin (); st.erase (st.begin ());
		int u = tmp.second.first, used = tmp.second.second;
		if (u == f)
		{
			printf ("%d\n", tmp.first);
			return 0;
		}
		if (tmp.first == d [u][used])
		{
			for (int i = 0; i < adj [u].size (); ++i)
			{
				int v = adj [u][i].first, w = adj [u][i].second;
				if (d [v][used] > d [u][used] + w)
				{
					if (d [v][used] != 1e9) st.erase (make_pair (d [v][used], make_pair (v, used)));
					d [v][used] = d [u][used] + w;
					st.insert (make_pair (d [v][used], make_pair (v, used)));
				}
			}
			if (!used)
				for (int i = 0; i < adj [u].size (); ++i)
				{
					int v = adj [u][i].first;
					if (d [v][1] > d [u][0])
					{
						if (d [v][1] != 1e9)
							st.erase (make_pair (d [v][1], make_pair (v, 1)));
						d [v][1] = d [u][0];
						st.insert (make_pair (d [v][1], make_pair (v, 1)));
					}
				}
		}
	}
	
	printf ("-1\n");
	return 0;
}
