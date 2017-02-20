#include <stdio.h>

int a[2309];
int F[2309][2309];
int V[2309][2309];
int n;

bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }

int f(int p, int q, bool tracing=false){
    int pp, qq, i, d;
    int r = 999999999;

    if (p>q) return 0;
    if (p==q) {
        if (tracing) printf("%d %d\n", p-1, q-1);
        return 1;
    }
    if (V[p][q] && !tracing) return F[p][q];

    if (a[p]==a[q]) {
        pp=p; qq=q;
        while (a[pp]==a[p]) pp++;
        while (a[qq]==a[q]) qq--;
        r=f(pp, qq);
        d=0;
    }

    else {
        for (i=p; i<=q-1; i++)
        if (minimize(r, f(p, i) + f(i+1, q))) d=i;
    }

    if (tracing){
        if (d==0) { f(pp, qq, true); printf("%d %d\n", p-1, q-1); }
        else { f(p, d, true); f(d+1, q, true); }
    }

    V[p][q] = true;
    F[p][q] = r;
    //printf("f(%d, %d) = %d\n", p, q, r);
    return r;
}

main(){
    int i, p, q;
    scanf("%d%d", &p, &q);
    n=p*q;
    for (i=1; i<=n; i++){
        scanf("%d", &a[i]);
        a[i]++;
    }
    printf("%d\n", f(1, n));
    f(1, n, true);
}
