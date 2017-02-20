#include <stdio.h>

struct bit_tree {
    int m, n;
    int T[2309][2309];
    void clear(int M, int N) { int i, j; m=M,n=N; for (int ii=1; i<=m; i++) for (j=1; j<=n; j++) T[i][j]=0; }
    void update(int p, int q, int v){ int i, j; for (i=p; i<=m; i+=i&-i) for (j=q; j<=n; j+=j&-j) T[i][j]+=v; }
    int get(int p, int q){ int i, j; int r=0; for (i=p; i>=1; i-=i&-i) for (j=q; j>=1; j-=j&-j) r += T[i][j]; return r; }
};

bit_tree tr;

main(){
	freopen("mobiles.inp", "r", stdin);
	freopen("mobiles.out", "w", stdout);

    int cc, p, q, w, pp, qq;
    for (;;){
        scanf("%d", &cc);
        if (cc==0) {
            scanf("%d", &p);
            p++,q++,pp++,qq++;
            tr.clear(p, p);
        }
        else if (cc==1){
            scanf("%d%d%d", &p, &q, &w);
            p++,q++,pp++,qq++;
            tr.update(p, q, w);
        }
        else if (cc==2){
            scanf("%d%d%d%d", &p, &q, &pp, &qq);
            p--, q--;
            p++,q++,pp++,qq++;
            printf("%d\n", tr.get(pp,qq) - tr.get(pp,q) - tr.get(p,qq) + tr.get(p,q));
        }
        else if (cc==3){
            return 0;
        }
    }
}


