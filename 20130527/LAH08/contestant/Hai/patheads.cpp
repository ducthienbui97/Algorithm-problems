#include <stdio.h>
#define MAX 100000+1

int A[MAX], B[MAX];

int main()
{
    freopen("patheads.inp", "r", stdin);
    freopen("patheads.out", "w", stdout);
    int n, i=0, j;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
        B[i]=0;
        for(j=i-1; j>=0; j--)
            if(A[j]%A[i]==0)
                B[j]++;
    }
    for(i=1; i<n; i++)
        for(j=i-1; j>=0; j--)
            if(A[i]%A[j]==0)
                B[i]++;
    for(i=0; i<n-1; i++)
        printf("%d\n", B[i]);
    printf("%d", B[n-1]);
    return 0;
}
