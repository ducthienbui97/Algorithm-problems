#include<stdio.h>
#define MAX   30303
int a[MAX];
int s[MAX];
int f[MAX][505];
int n,k,w;
int t,c;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&w);
    s[0]=0;
    int i,j;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        for (j=1;j<=k;j=j+1) f[i][j]=-1;
    }
}
/*int opt(int i,int j) {
    if (j*w>=i) return (s[i]);
    if (j==0) return (0);
    if (i==0) return (0);
    if (i<w) return (s[i]);
    if (f[i][j]>0) return (f[i][j]);
    f[i][j]=max(opt(i-1,j),opt(i-w,j-1)+s[i]-s[i-w]);
    return (f[i][j]);
}*/
void optimize(void) {
    int i,j;
    for (i=1;i<=n;i=i+1)
        for (j=1;j<=k;j=j+1) {
            if (j*w>=i) f[i][j]=s[i];
            else {
                f[i][j]=f[i-1][j];
                if (f[i-w][j-1]+s[i]-s[i-w]>f[i][j]) f[i][j]=f[i-w][j-1]+s[i]-s[i-w];
            }
        }
    printf("%d\n",f[n][k]);
}
int main(void) {
    freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    scanf("%d",&t);
    for (c=1;c<=t;c=c+1) {
        init();
        if (k*w>=n) printf("%d\n",s[n]);
        else optimize();
    }
}
