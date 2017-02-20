#include <stdio.h>

double S, H, V;
int n;
double a[2309];
double d[2309];
double v[2309];

main(){
    freopen("barrel.inp", "r", stdin);
    freopen("barrel.out", "w", stdout);

    int i;
    scanf("%lf%lf%lf", &S, &H, &V);
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    scanf("%lf%lf", &a[i], &d[i]);

    for (i=1; i<=n; i++){
        v[i]=a[i]*a[i]*a[i];
        if (d[i]<1) v[i]*=d[i];
    }

    for (i=1; i<=n; i++)
    V += v[i];
    printf("%.7lf\n", V/S);
}
