#include<algorithm>
#include<iostream>
#include<cassert>
#include<vector>
#include<cstdio>
using namespace std;

struct Point {
	long long x, y;

	Point(long long x = 0, long long y = 0): x (x), y (y) {}

	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}

	Point rot90() const {
		return Point(-y, x);
	}
};

ostream& operator << (ostream &out, const Point &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}

long long cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

int sgn(long long x) {
	return x < 0 ? -1 : x > 0 ? 1 : 0;
}

int ccw(const Point &a, const Point &b, const Point &c) {
	return sgn(cross(b - a, c - a));
}

bool solarCompare(const Point &a, const Point &b) {
	return cross(a, b) > 0;
}

bool coorCompare(const Point &a, const Point &b) {
	return a.y != b.y ? a.y > b.y : a.x < b.x;
}

struct Line {
	long long a, b, c;

	Line(const Point &x, const Point &y) {
		Point n = (cross(x, y) > 0 ? x - y : y - x).rot90();
		a = n.x;
		b = n.y;
		c = -(a * x.x + b * x.y);
	}

	long long apply(const Point &p) const {
		return a * p.x + b * p.y + c;
	}
};

const int N = (int) 1e5;
vector<Point> hull[4 * N];
int n, nQuery;
Point p[N];

void enter() {
	cin >> n >> nQuery;
	for(int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		p[i] = Point(x, y);
	}
}

void init(int k, int l, int r) {
	vector<Point> x;
	if(r - l > 1) {
		init((k << 1) + 1, l, (l + r) >> 1);
		init((k << 1) + 2, (l + r) >> 1, r);
		x.insert(x.end(), hull[(k << 1) + 1].begin(), hull[(k << 1) + 1].end());
		x.insert(x.end(), hull[(k << 1) + 2].begin(), hull[(k << 1) + 2].end());
	} else {
		x.push_back(p[l]);
	}
	sort(x.begin(), x.end(), coorCompare);
	for(int i = 0, j = 0; i < (int) x.size(); ++i) {
		while(j > 1 && ccw(hull[k][j - 2], hull[k][j - 1], x[i]) <= 0) {
			hull[k].pop_back();
			--j;
		}
		hull[k].push_back(x[i]);
		++j;
	}
}

long long get(int k, int l, int r, int x, int y, const Line &d) {
	if(max(l, x) >= min(r, y)) return 0;
	if(x <= l && r <= y) {
		int low = 0, high = (int) hull[k].size() - 1;
		while(low < high) {
			int mid = (low + high) >> 1;
			if(d.apply(hull[k][mid]) <= d.apply(hull[k][mid + 1]))
				high = mid;
			else
				low = mid + 1;
		}
		return d.apply(hull[k][low]);
	} else {
		return min(get((k << 1) + 1, l, (l + r) >> 1, x, y, d), get((k << 1) + 2, (l + r) >> 1, r, x, y, d));
	}
}

void solve() {
	for(int i = 0; i < nQuery; ++i) {
		int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
		Point a (x0, y0), b (x1, y1);
		if(cross(a, b) < 0) swap(a, b);
		int l = lower_bound(p, p + n, a, solarCompare) - p;
		int r = upper_bound(p, p + n, b, solarCompare) - p;
		Line d (a, b);
		printf("%c\n", get(0, 0, n, l, r, d) < 0 ? 'Y' : 'N');
	}
}

int main() {
	//assert(freopen("tri.inp", "r", stdin));
	//assert(freopen("tri.out", "w", stdout));
	ios::sync_with_stdio(false);
	enter();
	sort(p, p + n, solarCompare);
	init(0, 0, n);
	solve();
	return 0;
}
