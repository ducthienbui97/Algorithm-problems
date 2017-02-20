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

int m, n, h [111][111], res, s, largest, S, cnt;
bool mark [111][111], dir [111][111][4];

void dfs (int x, int y)
{
	mark [x][y] = 1;
	
	int dx [] = {1, 0, -1, 0}, dy [] = {0, -1, 0, 1};
	
	for (int i = 0; i < 4; ++i)
	{
		int xx = x + dx [i], yy = y + dy [i];
		
		if (!dir [xx][yy][(i + 2) % 4])
		{
			s += abs (h [xx][yy] - h [x][y]);
			dir [x][y][i] = 1;
		}
		if (!mark [xx][yy] && h [xx][yy]) dfs (xx, yy);
	}
}

int main (int argc, char **argv)
{
	freopen ("PAINTING.INP", "r", stdin);
	freopen ("PAINTING.OUT", "w", stdout);
	scanf ("%d%d", &m, &n);
	
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			scanf ("%d", &h [i][j]);
	
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (h [i][j] && !mark [i][j])
			{
				s = 0;
				++cnt;
				dfs (i, j);
				res += s;
				if (s > S)
				{
					S = s;
					largest = cnt;
				}
			}
			
	printf ("%d\n%d\n", cnt, res);
	printf ("%d %d\n", largest, S);
				
	return 0;
}
