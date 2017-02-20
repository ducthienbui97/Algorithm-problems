#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FORE(i, v) for(__typeof((v).begin())i=(v).begin(); i!=(v).end(); ++i)
#define FORD(i, a, b) for(int i=(a); i>=(b); --i)
#define REPD(i, n) for(int i=(n)-1; i>=0; --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int, int> PII;
typedef set<PII>::iterator IT;
const int INF = 1e9+7;

const int N = 1e6+6, V = 2e6+7;
PII a[N], d[N], bit[V];
int b[N], f[N], trace[N][19];

PII cal(PII x, PII y) {
    if (x.F!=y.F) return max(x, y);
    if (d[x.S].F<d[y.S].F) return y;
    return x;
}

void upd(int x, PII v) {
    for (; x<V; x+=x&-x) bit[x]=cal(bit[x], v);
}

PII get(int x) {
    PII r;
    for (; x; x-=x&-x) r=cal(r, bit[x]);
    return r;
}

bool cmp(int x, int y) {
    return d[x]<d[y];
}

int jump(int x, int y) {
    int tot=0;
    for (int j=18; j>=0; --j) if (d[trace[y][j]].F>d[x].S) tot+=1<<j, y=trace[y][j];
    tot++;
    return tot;
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> c;
    FOR(i, 2, n+1) scanf("%d%d", &a[i].F, &a[i].S);
    a[1]=MP(0, 0); a[n+2]=MP(INF, INF);
    FOR(i, 1, n+2) c.PB(a[i].F), c.PB(a[i].S);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    FOR(i, 1, n+2) d[i].F=lower_bound(c.begin(), c.end(), a[i].F)-c.begin()+1,
                d[i].S=lower_bound(c.begin(), c.end(), a[i].S)-c.begin()+1;
    FOR(i, 1, n+2) b[i]=i;
    sort(b+1, b+n+3, cmp);
    int ans=0;
    for (int i=1; i<=n+2; ++i) {
        int x=b[i];
        PII u=get(d[x].F-1);
        f[x]=u.F; ++f[x]; trace[x][0]=u.S;
//        printf("%d %d %d %d %d\n", x, d[x].F, d[x].S, f[x], trace[x][0]);
        ans=max(ans, f[x]);
        upd(d[x].S, MP(f[x], x));
    }
    printf("%d\n", ans-2);
    for (int j=1; j<=18; ++j)
        for (int i=1; i<=n+2; ++i)
            trace[i][j]=trace[trace[i][j-1]][j-1];
    set<PII> s;
    s.insert(MP(d[1].F, 1)); s.insert(MP(d[n+2].F, n+2));
    FOR(i, 2, n+1) {
        IT x=s.lower_bound(MP(d[i].F, 0)); if (x!=s.end()) --x; else continue;
        IT y=s.upper_bound(MP(d[i].F, 0)); if (y==s.end()) continue;
        if (d[x->S].S<d[i].F && d[i].S<d[y->S].F) {
            int u=jump(x->S, i);
            int v=jump(i, y->S);
//            printf("%d %d %d %d %d\n", x->F, y->S, u, v, f[y->S]-f[x->S]);
            if (u+v>=f[y->S]-f[x->S]) s.insert(PII(d[i].F, i));
        }
    }
    vector<int> res;
    FORE(it, s) {
//        if ((it->S)>=2 && (it->S)<=n+1)
         res.PB(it->S);
    }
    sort(res.begin(), res.end());
    FORE(it, res) {
        if (*it>=2 && *it<=n+1) printf("%d ", *it-1);
    }
    return 0;
}















