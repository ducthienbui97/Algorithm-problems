#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <limits>
#include <string>
#include <locale>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <map>
#include <set>

#define maxN 10000
#define INF 1000000000

using namespace std;
int n, m, k;
int t[50000];
int pp[50000];
int a[50000];
bool check(int a[])
{
	sort(a, a+m);
	int sum = 0;
	for(int i=m-1; i>=m-n; i--) sum += a[i];
	return (sum >= k);
}

void process()
{
	int l = 0, h = INF;
	for(int p = 1; p<=32; p++)
	{
		long long mid = (l+h)/2;
		for(int i=0; i<m; i++)
		{
			a[i] = (mid - t[i])/pp[i] +1 ;
		}
		if(!check(a)) l = mid + 1;
		else h = mid - 1;
	}
	cout << l << endl;
}

int main()
{
	freopen("SQUIRREL.INP", "r", stdin);
	freopen("SQUIRREL.OUT", "w", stdout);
	cin >> m >> n >> k ;
	for(int i=0; i<m; i++) cin >> t[i];
	for(int i=0; i<m; i++) cin >> pp[i];
	process();
	return 0;
}
