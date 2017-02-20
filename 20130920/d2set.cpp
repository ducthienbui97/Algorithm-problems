#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;

#define TR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
const int N = 1e6;
map<int, vector<int> > mp;
int a[N], n, k;

void enter() {
	for(int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
	int s = 0, d = 1;
	for(int i = 0; i < n; ++i) {
		int x = a[i], c = 0;
		while(~x & 1) x >>= 1, ++c;
		mp[x].push_back(c);
	}
	TR(mp, it) {
		const vector<int> &v = it->second;
		for(vector<int>::const_iterator i = v.begin(), j = v.begin(); i != v.end(); ++j)
			if(j == v.end() || j - i != *j - *i) {
				int n = j - i;
				s += (n + 1) >> 1;
				if(~n & 1) d = d * ((n >> 1) + 1LL) % k;
				i = j;
			}
	}
	cout << s << ' ' << d << endl;
}

int powmod(int a, int n) {
	int res = 1;
	for(; n > 0; n >>= 1) {
		if(n & 1) res = 1LL * res * a % k;
		a = 1LL * a * a % k;
	}
	return res;
}

void subtask3() {
	int s = 0, d = 1;
	for(int k = 0; 1 << k <= n; ++k) {
		int low = n >> (k + 1), high = n >> k;
		if(~low & 1) ++low;
		if(~high & 1) --high;
		if(low <= high) {
			int nnum = (high - low) / 2 + 1;
			s += nnum * ((k / 2) + 1);
			if(k & 1) d = 1LL * d * powmod(((k + 1) >> 1) + 1LL, nnum) % k;
		}
	}
	cout << s << ' ' << d << endl;
}

int main() {
	freopen("d2set.inp", "r", stdin);
	freopen("d2set.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(n > N) subtask3();
	else enter(), solve();
	return 0;
}
