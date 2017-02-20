#include <stdio.h>
#include <string.h>

long a[1000005], c[1000005];
bool sign[1000005];

main(){
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    long n, i, j, maxi= 0;
    scanf("%ld", &n);
    memset(a, 0, sizeof a);
    for(i=1;i<=n;i++){
        scanf("%ld", &c[i]);
        sign[c[i]]= true;
        if(c[i]>maxi) maxi= c[i];
    }
    for(i=1;i<=n;i++){
        for(j=c[i];j<=maxi;j+=c[i]){
            if(sign[j]==true) a[j]++;
        }
    }
    for(i=1;i<=n;i++){
        printf("%ld\n", a[c[i]]-1);
    }
}
