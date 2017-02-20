#include<stdio.h>
#define MAX   5001
int a[MAX];
int s[MAX];
int f[MAX][MAX*10];
int n,p;
void init(void) {
    int i;
    scanf("%d",&p);
    scanf("%d",&n);
    s[0]=0;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
}
int r(int i,int j) {
    if (i*j==0) return (0);
    if (j>=s[i]) return (s[i]);
    else return (f[i][j]);
}
void optimize(void) {
    int i,j;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=p;j=j+1) {
            if (j>=s[i]) break;
            f[i][j]=r(i-1,j);
            if ((j>=a[i]) && (r(i-1,j-a[i])+a[i]>f[i][j])) f[i][j]=r(i-1,j-a[i])+a[i];
        }
    printf("%d",r(n,p));
}
int main(void) {
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    init();
    optimize();
    return 0;
}
