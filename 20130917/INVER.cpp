#include <iostream>
#include <set>
#include <queue>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORE(i, v) for (__typeof ((v).begin ()) i = (v).begin (); i != (v).end (); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef pair <int, int> PII;

const int N = 1e6 + 3;
vector <int> adj [N], cand;
int n, a [N], qu [N], front, back, id [N];
vector <int> ans [N];

int main () {
	freopen ("INVER.INP", "r", stdin);
	freopen ("INVER.OUT", "w", stdout);
    scanf ("%d", &n);
    FOR (i, 1, n) scanf ("%d", &a [i]);
    FOR (i, 1, n) {
    	int best = i;
    	while (cand.size ()) {
    		int j = cand.back ();
    		if (a [j] < a [i]) break;
    		if (a [j] > a [best]) best = j;
    		adj [i].PB (j);
    		adj [j].PB (i);
    		cand.pop_back ();
    	}
    	cand.push_back (best);
    }

    int anscnt = 0;
    FOR (i, 1, n) if (!id [i]) {
    	front = 1; back = 0;
    	qu [++back] = i;
    	id [i] = ++anscnt;
    	while (front <= back) {
    		int u = qu [front++];
    		FORE (i, adj [u]) if (!id [*i]) {
    			id [*i] = anscnt;
    			qu [++back] = *i;
    		}
    	}
    }

    FOR (i, 1, n) ans [id [i]].PB (i);
    printf ("%d\n", anscnt);
    FOR (i, 1, anscnt) {
    	printf ("%d", ans [i].size ());
    	FORE (j, ans [i]) printf (" %d", *j);
    	puts ("");
    }
	return 0;
}

