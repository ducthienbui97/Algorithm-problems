#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> ii;
int lim, n;
int a[12309];
map<ii, ii> F;

int min(int a, int b){ return a>b?b:a; }

int f(int pos, int rem){
    if (rem<0) return -999999999;
    if (pos==n+1) return 0;
    if (F[ii(pos, rem)].first)
    return F[ii(pos, rem)].second;

    int d1 = f(pos+1, rem-a[pos]) + a[pos];
    int d2 = f(pos+1, rem);
    int r = max(d1, d2);
    //printf("f(%d, %d) = %d\n", pos, rem, r);
    F[ii(pos, rem)] = ii(true, r);
    return r;
}

main(){
    int i;
    freopen("hay4sale.inp", "r", stdin);
    freopen("hay4sale.out", "w", stdout);
    scanf("%d%d", &lim, &n);
    for (i=1; i<=n; i++)
    scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    printf("%d\n", f(1, lim));
}
