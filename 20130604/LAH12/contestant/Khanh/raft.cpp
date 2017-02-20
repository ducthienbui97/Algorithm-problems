#include<cstdio>
#include<complex>
#include<algorithm>
#include<cfloat>
using namespace std;

typedef complex<double> Point;

double dot(const Point &a, const Point &b) {
	return (conj(a) * b).real();
}

double cross(const Point &a, const Point &b) {
	return (conj(a) * b).imag();
}

double distPS(const Point &p, const Point &q1, const Point &q2) {
	if(dot(q2 - q1, p - q1) < 0) return abs(p - q1);
	if(dot(q2 - q1, p - q2) > 0) return abs(p - q2);
	return abs(cross(q2 - q1, p - q1)) / abs(q2 - q1);
}

const int N = 100+7;
int n, m;
Point p1[N], p2[N];

void enter(int &n, Point p[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf", &p[i].real(), &p[i].imag());
}

void solve() {
	double res = DBL_MAX;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			res = min(res, distPS(p1[i], p2[j], p2[(j+1)%m]));
			res = min(res, distPS(p2[j], p1[i], p1[(i+1)%n]));
		}
	printf("%.6lf\n", res / 2);
}

int main() {
	freopen("raft.inp", "r", stdin);
	freopen("raft.out", "w", stdout);
	enter(n, p1);
	enter(m, p2);
	solve();
	return 0;
}
