/*started: 			AC in: 				*/
#include <cstdio>
int a[1111111], n, b[1111111];
void process() {
    int i, j, k;
    a[1]=0;
    a[2]=1;
    for (i=2; i<=n; i++) {
        int end=1<<(i-1);
        int mir=1<<i;
        for (j=end; j>=1; j--) {
            a[mir+1-j]=a[j];
            a[mir+1-j]=a[mir+1-j]+(1<<(i-1));
        }
    }
    for (i=1; i<=(1<<n); i++) {
        for (j=n-1; j>=0; j--) {
            if (a[i]&(1<<j)) printf ("1");
            else printf ("0");
        }
        printf ("\n");
    }
}
int main() {
    freopen ("grey.inp", "r", stdin);
    freopen ("grey.out", "w", stdout);
    scanf ("%d", &n);
    process();
}
