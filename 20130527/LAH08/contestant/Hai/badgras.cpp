#include <stdio.h>
#define MAX 1000+1
int A[MAX][MAX], ans=0, counter=0;
bool B[MAX][MAX];

void process(int i, int j)
{
    if(A[i][j]==0||i<1||j<1||B[i][j])
        return;
    else
    {
        counter++;
        B[i][j]=true;
        process(i+1, j);
        process(i-1, j);
        process(i, j+1);
        process(i, j-1);
        process(i-1, j-1);
        process(i-1, j+1);
        process(i+1, j-1);
        process(i+1, j+1);
    }
}

int main()
{
    freopen("badgras.inp", "r", stdin);
    freopen("badgras.out", "w", stdout);
    int r, c, i, j;
    scanf("%d %d", &r, &c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            scanf("%d", &A[i][j]);
            if(A[i][j]==0)
                B[i][j]=true;
            else B[i][j]=false;
        }
    }
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            if(!B[i][j])
            {
                process(i, j);
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
