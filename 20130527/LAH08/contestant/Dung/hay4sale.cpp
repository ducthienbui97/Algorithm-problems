#include <stdio.h>
#include <algorithm>

using namespace std;

long f[50001][5000];
long v[5001];

main(){
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    long i, n, h, c, j;
    scanf("%ld%ld", &c, &n);
    for(i=1;i<=n;i++){
        scanf("%ld", &v[i]);
    }
    for(i=0;i<=c;i++) f[i][0]= 0;
    sort(v+1,v+n+1);
    for(j=1;j<=n;j++)
        for(i=0;i<=c;i++){
            if(i>= v[j]) f[i][j]= max(f[i-v[j]][j-1]+v[j], f[i][j-1]);
            else f[i][j]= f[i][j-1];
        }
    printf("%ld\n", f[c][n]);
}
