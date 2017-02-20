#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 1000, INF = 1e9;
int n, goal, vx[N], vy[N], x[N], y[N], cx, cy;

void enter() {
	cin >> cx >> cy >> n >> goal;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> vx[i] >> vy[i];
		vx[i] -= x[i]; vy[i] -= y[i];
	}
}

double sqr(const double &x) {
	return x * x;
}

int maxCatch(double radius) {
	vector<pair<double, int> > v;
	for(int i = 0; i < n; ++i)
		if(vx[i] != 0 || vy[i] != 0) {
			double tx = x[i] - cx, ty = y[i] - cy;
			double a = sqr(vx[i]) + sqr(vy[i]);
			double b = 2 * (tx * vx[i] + ty * vy[i]);
			double c = sqr(tx) + sqr(ty) - sqr(radius);
			double d = sqr(b) - 4 * a * c;
			if(d < 0) continue;
			d = sqrt(d);
			double t1 = (-b + d) / (2 * a), t2 = (-b - d) / (2 * a);
			if(t1 > t2) swap(t1, t2);
			if(t2 <= 0) continue;
			v.push_back(make_pair(t1, -1));
			v.push_back(make_pair(t2, 1));
		} else if(sqr(x[i] - cx) + sqr(y[i] - cy) <= sqr(radius)) {
			v.push_back(make_pair(-INF, -1));
			v.push_back(make_pair(INF, 1));
		}
	sort(v.begin(), v.end());
	int curr = 0, res = 0;
	for(unsigned i = 0; i < v.size(); ++i)
		res = max(res, curr -= v[i].second);
	return res;
}

void solve() {
	double l = 0, r = INF;
	for(int t = 0; t < 100; ++t) {
		double mid = (l + r) / 2;
		if(maxCatch(mid) >= goal) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(5) << (l + r) / 2 << endl;
}

int main() {
	freopen("fish.inp", "r", stdin);
	freopen("fish.out", "w", stdout);
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}
