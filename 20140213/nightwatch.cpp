#include <cstdio>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <numeric>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <cmath>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long double LD;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SIZE(X) (int)(X).size()
#define FOREACH(it,X) for (__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)

#define TASK "nightwatch"

#define MXN 510
#define INF 1e+9

struct wsp_t
{
    int x, y;
};

PII prz[MXN];
wsp_t wsp[MXN];
int pos[MXN];
int n, i;

wsp_t point(int x, int wx)
{
    wsp_t ret;
    ret.x = prz[x].ST;
    ret.y = pos[x];
    if (wx)
        ret.x = prz[x].ND;
    return ret;
}

int il(const wsp_t &o, const wsp_t &p, const wsp_t &src)
{
    return (o.x-src.x)*(p.y-src.y)-(o.y-src.y)*(p.x-src.x);
}

bool check(int a, int b, int wa, int wb)
{
    wsp_t p1 = point(a,wa);
    wsp_t p2 = point(b,wb);
    for (int c = a+1; c < b; c++ )
    {
        if (il(p2,point(c,1),p1) >= 0)
            return false;
        if (il(point(c,0),p2,p1) >= 0)
            return false;
    }
    return true;
}

LD dist(const wsp_t &o, const wsp_t &p)
{
    return sqrtl((LD)((o.x-p.x)*(o.x-p.x))+(LD)((o.y-p.y)*(o.y-p.y)));
}

pair<LD,LD> best[MXN];
bool cansee[MXN][MXN][2][2];
pair<bool,bool> fromdown[MXN], fromup[MXN];
PII tmp;

int main()
{
//  freopen("nightwatch.in", "r", stdin);
    freopen(TASK ".in","r",stdin);
    freopen(TASK ".out","w",stdout);
    scanf("%i", &n);
    for (int a = 0; a < n; a++ )
    {
        scanf("%i%i", &wsp[a].x, &wsp[a].y);
        pos[i++] = wsp[a].y;
    }
    sort(pos,pos+i);
    i = unique(pos,pos+i)-pos;
    for (int a = 0; a < i; a++ )
    {
        int x1 = -10000;
        int x2 = 10000;
        for (int b = 0; b < n; b++ )
            if (min(wsp[b].y,wsp[(b+1)%n].y) <= pos[a] && pos[a] <= max(wsp[b].y,wsp[(b+1)%n].y))
            {
                if (wsp[b].y < wsp[(b+1)%n].y)
                {
                    assert(wsp[b].x == wsp[(b+1)%n].x);
                    x2 = min(x2,wsp[b].x);
                }
                if (wsp[b].y > wsp[(b+1)%n].y)
                {
                    assert(wsp[b].x == wsp[(b+1)%n].x);
                    x1 = max(x1,wsp[b].x);
                }
            }
        prz[a].ST = x1;
        prz[a].ND = x2;
    }

    int y1 = pos[i-1];
    int y2 = pos[0];

    for (int a = 0; a < n; a++ )
    {
        if (wsp[a].x < wsp[(a+1)%n].x)
        {
            assert(wsp[a].y == wsp[(a+1)%n].y);
            y2 = max(y2, wsp[a].y);
        }
        if (wsp[a].x > wsp[(a+1)%n].x)
        {
            assert(wsp[a].y == wsp[(a+1)%n].y);
            y1 = min(y1, wsp[a].y);
        }
    }

    if (y1 >= y2)
    {
        double res = 0.;
        if (prz[0].ND < prz[i-1].ST)
            res = (double)(prz[i-1].ST-prz[0].ND);
        if (prz[0].ST > prz[i-1].ND)
            res = (double)(prz[0].ST-prz[i-1].ND);
        printf("%.10lf\n", res*2.);
        return 0;
    }

    int p1 = 0;
    while (pos[p1] < y1)
        p1++;
    int p2 = i-1;
    while (pos[p2] > y2)
        p2--;

    if (prz[0].ND >= prz[p1].ST && prz[0].ST <= prz[p1].ND)
    {
        prz[p1].ST = max(prz[p1].ST, prz[0].ST);
        prz[p1].ND = min(prz[p1].ND, prz[0].ND);
    }

    tmp = prz[0];
    for (int a = p1; a <= p2; a++ )
    {
        tmp.ST = max(tmp.ST, prz[a].ST);
        tmp.ND = min(tmp.ND, prz[a].ND);
        if (tmp.ST > tmp.ND)
            break;
        if (tmp.ST <= prz[a].ST && prz[a].ST <= tmp.ND)
            fromdown[a].ST = true;
        if (tmp.ST <= prz[a].ND && prz[a].ND <= tmp.ND)
            fromdown[a].ND = true;
    }

    if (prz[i-1].ND >= prz[p2].ST && prz[i-1].ST <= prz[p2].ND)
    {
        prz[p2].ST = max(prz[p2].ST, prz[i-1].ST);
        prz[p2].ND = min(prz[p2].ND, prz[i-1].ND);
    }

    tmp = prz[i-1];
    for (int a = p2; a >= p1; a-- )
    {
        tmp.ST = max(tmp.ST, prz[a].ST);
        tmp.ND = min(tmp.ND, prz[a].ND);
        if (tmp.ST > tmp.ND)
            break;
        if (tmp.ST <= prz[a].ST && prz[a].ST <= tmp.ND)
            fromup[a].ST = true;
        if (tmp.ST <= prz[a].ND && prz[a].ND <= tmp.ND)
            fromup[a].ND = true;
    }

    for (int a = p1; a <= p2; a++ )
    {
        best[a].ST = INF;
        best[a].ND = INF;
        for (int b = a+1; b <= p2; b++ )
        {
            cansee[a][b][0][0] = check(a, b, 0, 0);
            cansee[a][b][0][1] = check(a, b, 0, 1);
            cansee[a][b][1][0] = check(a, b, 1, 0);
            cansee[a][b][1][1] = check(a, b, 1, 1);
        }
    }

    wsp_t p = point(0,0); p.y = pos[p1];
    wsp_t q = point(0,1); q.y = pos[p1];
    best[p1].ST = min(dist(p, point(p1,0)), dist(q, point(p1,0)));
    best[p1].ND = min(dist(p, point(p1,1)), dist(q, point(p1,1)));

    LD res = INF;
    for (int a = p1; a <= p2; a++ )
    {
        if (fromdown[a].ST)
            best[a].ST = min(best[a].ST, (LD)(pos[a]-pos[p1]));
        if (fromdown[a].ND)
            best[a].ND = min(best[a].ND, (LD)(pos[a]-pos[p1]));
        if (fromup[a].ST)
            res = min(res, best[a].ST + (LD)(pos[p2]-pos[a]));
        if (fromup[a].ND)
            res = min(res, best[a].ND + (LD)(pos[p2]-pos[a]));
        for (int b = a+1; b <= p2; b++ )
        {
            if (cansee[a][b][0][0])
                best[b].ST = min(best[b].ST, best[a].ST + dist(point(a,0),point(b,0)));
            if (cansee[a][b][0][1])
                best[b].ND = min(best[b].ND, best[a].ST + dist(point(a,0),point(b,1)));
            if (cansee[a][b][1][0])
                best[b].ST = min(best[b].ST, best[a].ND + dist(point(a,1),point(b,0)));
            if (cansee[a][b][1][1])
                best[b].ND = min(best[b].ND, best[a].ND + dist(point(a,1),point(b,1)));
        }
    }

    p = point(i-1,0); p.y = pos[p2];
    q = point(i-1,1); q.y = pos[p2];

    res = min(res, best[p2].ST + min(dist(p, point(p2,0)), dist(q, point(p2,0))));
    res = min(res, best[p2].ND + min(dist(p, point(p2,1)), dist(q, point(p2,1))));

    printf("%.10lf\n", (double)(res*2.));

    return 0;
}
