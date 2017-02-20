#include <stdio.h>

int A[500+1];

int main()
{
    freopen("hayexp.inp", "r", stdin);
    freopen("hayexp.out", "w", stdout);
    int n, q, i, a, b, sum=0;
    scanf("%d %d", &n, &q);
    for(i=1; i<=n; i++)
        scanf("%d", &A[i]);
    while(q--)
    {
        scanf("%d %d", &a, &b);
        for(i=a; i<=b; i++)
            sum+=A[i];
        printf("%d", sum);
        if(q!=2)
            printf("\n");
        sum=0;
    }
    return 0;
}
