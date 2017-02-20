#include<stdio.h>
#define MAX   10101
int f[MAX];
int a[MAX][MAX];
int n;
void init(void) {
    scanf("%d",&n);
    int x,y;
    while (true) {
        scanf("%d",&x);
        scanf("%d",&y);
        if ((x==0) && (y==0)) return;
        a[x][y]=1;
    }
}
void optimize(void) {
    f[1]=1;
    int i,j;
    for (i=2;i<=n;i=i+1) {
        f[i]=0;
        for (j=1;j<i;j=j+1) f[i]=f[i]+a[j][i]*f[j];
    }
    printf("%d",f[n]);
}
int main(void) {
    freopen("2.inp","r",stdin);
    freopen("2.out","w",stdout);
    init();
    optimize();
}
