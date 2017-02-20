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

int m, n, idx [202][202], t, k;
long long c [202][202], d [202][202][64];
int dx [] = {-1, 0, 0, 1}, dy [] = {0, -1, 1, 0};

vector <long long> vec (long long x1, long long x2, long long x3, long long x4)
{
	vector <long long> v;
	v.push_back (x1);
	v.push_back (x2);
	v.push_back (x3);
	v.push_back (x4);
	return v;
}

int main (int argc, char **argv)
{
	#ifndef _
		freopen ("XYZ.INP", "r", stdin);
		freopen ("XYZ.OUT", "w", stdout);
	#endif
	memset (idx, -1, sizeof idx);
	for (int i = 0; i < 202; ++i)
		for (int j = 0; j < 202; ++j)
		{
			c [i][j] = (1LL << 60);
			for (int k = 0; k < 64; ++k)
				d [i][j][k] = (1LL << 60);
		}
				
	cin >> m >> n >> k >> t;
	
	for (int i = 0; i < k; ++i)
	{
		int x, y; cin >> x >> y;
		idx [x][y] = i;
	}
	
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c [i][j];
	
	set <vector <long long> > st;
	int tmp = (idx [1][1] != -1 ? 1 << idx [1][1] : 0);
	st.insert (vec (d [1][1][tmp] = c [1][1], 1, 1, tmp));
	
	while (st.size ())
	{
		vector <long long> tmp = *st.begin (); st.erase (st.begin ());
		int x1 = tmp [1], y1 = tmp [2], mask1 = tmp [3];
		if (tmp [0] == d [x1][y1][mask1])
			for (int i = 0; i < 4; ++i)
			{
				int x2 = x1 + dx [i], y2 = y1 + dy [i], mask2 = (mask1 | (idx [x2][y2] == -1 ? 0 : 1 << idx [x2][y2]));
				if (d [x2][y2][mask2] > d [x1][y1][mask1] + c [x2][y2])
				{
					if (d [x2][y2][mask2] != 1e9) st.erase (vec (d [x2][y2][mask2], x2, y2, mask2));
					d [x2][y2][mask2] = d [x1][y1][mask1] + c [x2][y2];
					st.insert (vec (d [x2][y2][mask2], x2, y2, mask2));
				}
			}
	}
	
	long long res = (1LL << 60);
	for (int i = 0; i < (1 << k); ++i)
		if (__builtin_popcount (i) >= t)
			res = min (res, d [m][n][i]);
	
	cout << res << endl;
	return 0;
}
