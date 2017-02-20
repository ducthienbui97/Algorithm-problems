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

int m, n, K, t [50001], p [50001];

bool ok (const int &k)
{
	priority_queue <int> pq;
	for (int i = 1; i <= m; ++i)
		pq.push (t [i] > k ? 0 : 1 + (k - t [i]) / p [i]);
	long long s = 0;
	for (int i = n; i--;)
	{
		s += pq.top ();
		pq.pop ();
	}
	
	return (s >= K);
}
	

int main (int argc, char **argv)
{
	freopen ("SQUIRREL.INP", "r", stdin);
	freopen ("SQUIRREL.OUT", "w", stdout);
	scanf ("%d%d%d", &m, &n, &K);
	for (int i = 1; i <= m; ++i) scanf ("%d", &t [i]);
	for (int i = 1; i <= m; ++i) scanf ("%d", &p [i]);
	
	int l = 1, r = 2e9;
	
	while (l < r)
	{
		int m = (l + r) / 2;
		if (ok (m)) r = m;
		else l = m + 1;
	}
	
	printf ("%d\n", l);
	return 0;
}
