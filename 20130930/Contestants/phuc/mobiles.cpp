#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
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

int n, t [1025][1025];

void upd (int x, const int &yy, const int &v) {
	for (; x <= n; x += x & -x) {
		int y = yy;
		for (; y <= n; y += y & -y) t [x][y] += v;
	}
}

int get (int x, const int &yy) {
	int s = 0;
	for (; x; x -= x & -x)
		for (int y = yy; y; y -= y & -y)
			s += t [x][y];
	return s;
}

int main (int ac, char **av) {
	freopen ("mobiles.inp", "r", stdin);
	freopen ("mobiles.out", "w", stdout);
	int t;

	while (scanf ("%d", &t), t != 3)
		if (!t) scanf ("%d", &n);
		else if (t == 1)  {
			int x, y, v; scanf ("%d%d%d", &x, &y, &v); ++x; ++y;
			upd (x, y, v);
		} else {
			int x1, y1, x2, y2; scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
			++x1; ++y1; ++x2; ++y2;
			int s = get (x2, y2) - get (x2, y1 - 1) - get (x1 - 1, y2) + get (x1 - 1, y1 - 1);
			printf ("%d\n", s);
		}

	return 0;
}

