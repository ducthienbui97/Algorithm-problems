#include <stdio.h>

main(){
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    long a[505], i, n, x, q, y;
    a[0]= 0;
    scanf("%ld%ld", &n, &q);
    for(i=1;i<=n;i++){
        scanf("%ld", &x);
        a[i]= a[i-1] + x;
    }
    for(i=1;i<=q;i++){
        scanf("%ld %ld", &x, &y);
        printf("%ld\n", a[y]-a[x-1]);
    }
}

