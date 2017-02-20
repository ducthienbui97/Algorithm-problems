#include <stdio.h>
#include <algorithm>

int A[5000+1];

int main()
{
    freopen("hay4sale.inp", "r", stdin);
    freopen("hay4sale.out", "w", stdout);
    int c, h, i, j, sum;
    scanf("%d %d", &c, &h);
    for(i=0; i<h; i++)
        scanf("%d", &A[i]);
    std::sort(A, A+h);
    int max=-1;
    for(i=0; i<h; i++)
    {
        sum=A[i];
        if(sum>max&&sum<=c)
            max=sum;
        if(sum>c)
            break;
        for(j=i+1; j<h; j++)
        {
            sum+=A[j];
            if(sum>max&&sum<=c)
                max=sum;
            if(sum>c)
                break;
        }
        sum=0;
    }
    printf("%d", max);
    return 0;
}
