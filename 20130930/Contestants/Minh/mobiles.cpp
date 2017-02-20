#include<cstdio>
#include<cstring>

const int N = 1030;
int tr[N][N], n;

void add(int x, int y, int v) {
    int i, j;
    for (i=x; i<=n; i+=i&-i)
        for (j=y; j<=n; j+=j&-j)
            tr[i][j]+=v;
}

int get(int x, int y) {
    int s=0, i, j;
    for (i=x; i>0; i-=i&-i)
        for (j=y; j>0; j-=j&-j)
            s+=tr[i][j];
    return s;
}

int get(int x1, int y1, int x2, int y2) {
        return get(x2, y2)-get(x2, y1-1)-get(x1-1, y2)+get(x1-1, y1-1);
}

void clear(int N) {
    n=N;
    int i, j;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++) tr[i][j]=0;
}

main() {
    freopen("mobiles.inp", "r", stdin);
    freopen("mobiles.out", "w", stdout);
    int code, u, v, w, t;
    for (; scanf("%d", &code) && code!=3;) {
        if (code==0) {
            scanf("%d", &u);
            clear(u);
        } else if (code==1) {
            scanf("%d%d%d", &u, &v, &w);
            ++u;
            ++v;
            add(u, v, w);
        } else if (code==2) {
            scanf("%d%d%d%d", &u, &v, &w, &t);
            ++u;
            ++v;
            ++w;
            ++t;
            printf("%d\n", get(u, v, w, t));
        }
    }
}
