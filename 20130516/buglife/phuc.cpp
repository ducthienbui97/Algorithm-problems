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

int t, n, m;
bool ok;
vector <int> adj [2002];
int mark [2002];

void dfs (int u)
{
	if (!ok) return;
	for (int i = 0; i < adj [u].size (); ++i)
	{
		int v = adj [u][i];
		if (mark [v])
		{
			if (mark [v] == mark [u])
				ok = 0;
		}
		else
		{
			mark [v] = -mark [u];
			dfs (v);
		}
			
	}
}

int main (int argc, char **argv)
{
	freopen ("BUGLIFE.INP", "r", stdin);
	freopen ("BUGLIFE.OUT", "w", stdout);
	scanf ("%d", &t);
	
	for (int test = 1; test <= t; ++test)
	{
		memset (mark, 0, sizeof mark);
		printf ("Scenario #%d:\n", test);
		
		scanf ("%d%d", &n, &m);
		
		for (int i = 1; i <= n; ++i) adj [i].clear ();
		
		while (m--)
		{
			int u, v; scanf ("%d%d", &u, &v);
			adj [u].push_back (v);
			adj [v].push_back (u);
		}
		
		ok = 1;
		
		for (int i = 1; i <= n; ++i)
			if (!mark [i])
			{
				mark [i] = 1;
				dfs (1);
			}
		
		cout << (!ok ? "Suspicious bugs found!" : "No suspicious bugs found!") << endl;
		
	}

	return 0;
}
