#include <stdio.h>

char a[239][239];
int n;

int rx[]={-1, -1, 1, 1};
int ry[]={-1, 1, -1, 1};

bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }

int back(int x, int y, int rem, bool tracing=false){
    int r = 999999999, i, xx, yy, d;

    if (tracing){
        printf("%d %d\n", x, y);
    }

    if (rem==0) return 0;
    if (x<1 or y<1 or x>n or y>n) return r;
    for (i=0; i<=3; i++){
        xx=x+rx[i];
        yy=y+ry[i];
        if (a[xx][yy] == 'o'){
            a[xx][yy] = '+';
            if (minimize(r, back(xx+rx[i], yy+ry[i], rem-1)+1)) { d=i; }
            a[xx][yy] = 'o';
        }
    }

    if (tracing){
        xx=x+rx[d];
        yy=y+ry[d];
        a[xx][yy] = '+';
        back(xx+rx[d], yy+ry[d], rem-1, true);
        a[xx][yy] = 'o';
    }

    //printf("back(%d, %d, %d) = %d\n", x, y, rem, r);
    return r;
}

main(){

    freopen("chkr.inp", "r", stdin);
    freopen("chkr.out", "w", stdout);

    int i, j, rem=0, x, y, r=999999999;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    scanf("%s", a[i]+1);

    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    if (a[i][j]=='o')
    rem += 1;

    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    if (a[i][j]=='K'){
        if (minimize(r, back(i, j, rem))){ x=i,y=j; }
    }
    if (r>=999999999) printf("impossible\n");
    else back(x, y, rem, true);
}
