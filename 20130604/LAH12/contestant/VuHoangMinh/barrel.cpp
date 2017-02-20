#include <cstdio>
#include <algorithm>
using namespace std;

double s, h, v, l[1005], d[1005], ans=0, add=0;
int n;

double tri(int z) {
    return z*z*z;
}

int main() {
    freopen ("barrel.inp", "r", stdin);
    freopen ("barrel.out", "w", stdout);
    int i;
    scanf ("%lf%lf%lf", &s, &h, &v);
    scanf ("%d", &n);
    for (i=1; i<=n; i++) {
        scanf ("%lf%lf", &l[i], &d[i]);
    }
    ans+=v/s;
//    printf ("%lf\n", ans);
    for (i=1; i<=n; i++) {
        add=max(add, tri(l[i])*d[i]/s);
    }
    if (add+ans<h)
        printf ("%.4lf", ans+add);
    else printf ("%.4lf", h);
}
