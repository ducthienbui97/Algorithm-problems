#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define maxn 1500 + 10
#define maxm 5000 + 10
#define oo 100000000000
int T [maxm], P [maxm];
long long n, m, k;

long long cal_time (int i, long long x)
{
	if ( T[i] > x ) return 0;
	if ( T[i] == x ) return 1;
	long long s = x - T[i];
	return 1 + s/P[i];
}

bool check(long long x)
{
	vector <long long> arr;
	for (int i=1; i<=m; i++) {
		arr. push_back(cal_time(i, x));
	}
	sort(arr. rbegin(), arr. rend());
	long long sum = 0;
	for (int i=0; i<n; i++) {
		sum+=arr[i];
	}
	if ( sum < k ) return false;
	return true;
}

long long BST()
{
	long long inf = 1, sup = oo;
	do {
		long long mid = (inf + sup)/2;
		if ( check(mid) ) sup = mid;
		else inf = mid;
	} while (inf + 1 < sup);
	if ( check(inf) ) return inf;
	return sup;
}

int main()
{
	cin >> m >> n >> k;
	for (int i=1; i<=m; i++)
		cin >> T[i];
	for (int i=1; i<=m; i++)
		cin >> P[i];
	cout << BST() << endl;	
	return 0;
}