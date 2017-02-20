#include<iostream>
#include<cassert>
#include<cstdio>
#include<stack>
using namespace std;

const int N = (int) 1e5;
int a[N], limLeft[N], limRight[N], n;
long long s[N + 1];

int main() {
//	assert(freopen("feelgood.inp", "r", stdin));
//	assert(freopen("feelgood.out", "w", stdout));
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	stack<int> st;
	for(int i = 0; i < n; ++i) {
		while(!st.empty() && a[i] <= a[st.top()]) st.pop();
		limLeft[i] = st.empty() ? 0 : st.top() + 1;
		st.push(i);
	}
	st = stack<int>();
	for(int i = n - 1; i >= 0; --i) {
		while(!st.empty() && a[i] < a[st.top()]) st.pop();
		limRight[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	long long best = 0;
	for(int i = 0; i < n; ++i)
		best = max(best, a[i] * (s[limRight[i]] - s[limLeft[i]]));
	cout << best;
	return 0;
}
