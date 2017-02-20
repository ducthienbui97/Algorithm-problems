#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int n, M[1000000][100], a[1000000];

void RMQ ()
{
    int i, j;
    for (j=1; 1<<j<=n; j++)
        for  (i=1; i+(1<<j-1) <=n; i++) {
        M[i][j]=max (M[i][j-1], M[i+(1<<(j-1))][j-1]);
        }
}

int log (int k)
{
    int i;
    for ( i=1; (1<<i)<=k; i++);
    return i-1;
}
int main ()
{
    int i, j, lim;
    scanf ("%d%d" ,&n, &lim);
    for (i=1; i<=n; i++) {
        scanf ("%d" ,&a[i]);
        M[i][0]=a[i];
    }
    RMQ();
    for (int k=1;k<=lim;k++) {
        int s=-1;
        scanf ("%d%d" ,&i, &j);
        int lg=log(j-i+1);
        int mx=j-i+1-(1<<lg);
        for (int z=0; z<=mx; z++) {
            s=max(s, M[i+z][lg]);
        }
        printf ("%d\n" ,s);
    }
}
