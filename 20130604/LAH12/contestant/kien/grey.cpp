#include <stdio.h>
#include <string.h>

char a[1230997][23];
int n, m, M;

void add(){
    int i;
    for (i=n+1; i<=2*n; i++)
    strcpy(a[i], a[2*n-i+1]);
    for (i=1; i<=n; i++) a[i][m-1]='0';
    for (i=n+1; i<=2*n; i++) a[i][m-1]='1';
    n*=2;
}

void show(){
    int i, j;
    for (i=1; i<=n; i++) a[i][M]=0;
    for (i=1; i<=n; i++)
    printf("%s\n", a[i]);
}

main(){
    freopen("grey.inp", "r", stdin);
    freopen("grey.out", "w", stdout);
    n=1;
    scanf("%d", &M);
    for (m=1; m<=M; m++) { add(); }
    show();
}
