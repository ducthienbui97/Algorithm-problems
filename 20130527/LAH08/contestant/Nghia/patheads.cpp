#include <cstdio>
#include <cmath>
#include <map>
#include <iostream>
#define MAX 100002
using namespace std;
int A[MAX];
int ap[1000002];
main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
        ap[A[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int sum=0,k=(int)sqrt(A[i]);
        for(int j=1;j<=k;j++)
        {
            if(A[i]%j==0)
            {
                sum+=ap[j];
                sum+=ap[A[i]/j];
            }
        }
        if(k*k==A[i]) sum-=ap[k];
        printf("%d\n",sum-1);
    }
}
