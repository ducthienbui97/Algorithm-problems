#include<stdio.h>
#define MAX   100010
int m,n;
int c[MAX*10];
int a[MAX];
int r[MAX];
void init(void) {
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
}
void process(void) {
    int i,j;
    for (i=1;i<=n;i=i+1) {
        r[i]=0;
        for (j=1;j*j<=a[i];j=j+1)
            if (a[i]%j==0) {
                r[i]=r[i]+c[j];
                if ((a[i]/j)!=j) r[i]=r[i]+c[a[i]/j];
            }
        printf("%d\n",r[i]-1);
    }
}
int main(void) {
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    init();
    process();
    return 0;
}
