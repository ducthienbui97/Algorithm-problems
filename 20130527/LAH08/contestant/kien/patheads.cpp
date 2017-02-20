#include <stdio.h>

int r[1230997];
int a[1230997];
int c[1230997];
bool b[1230997];
int n;

main(){
    freopen("patheads.inp", "r", stdin);
    freopen("patheads.out", "w", stdout);

    int i, j;
    scanf("%d", &n);
    for (i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if (c[a[i]]) b[i]=true;
        c[a[i]]++;
    }

    //for (i=1; i<=n; i++) printf("%d,", b[i]); printf("\n");

    for (i=1; i<=n; i++)
    if (!b[i])
    for (j=a[i]; j<=1000000; j+=a[i])
    r[j] += c[a[i]];

    for (i=1; i<=n; i++)
    printf("%d\n", r[a[i]]-1);

}
