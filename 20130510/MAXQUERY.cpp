#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#define elif else if
using namespace std;
typedef pair<int,int> pii;
int r[333333][33];
int a[333333];
int m2[33];
main()
{
    int i,j;
    int n,maxj,m;
    scanf("%d%d",&n,&m);
    maxj=log2(n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    m2[0]=1;
    for(int i=1;i<=n;i++)
    r[i][0]=a[i];
    for(int i=1;i<=maxj;i++)
        m2[i]=m2[i-1]<<1;

    for(int j=1;j<=maxj;j++)
    for(int i=1;i<=n-1<<j;i++)
    {
        r[i][j]=max(r[i][j-1],r[i+m2[j-1]][j-1]);
       // cout<<r[i][j]<<endl;
    }
    int k;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        k=log2(v-u+1);
      //  v=v-(1<<k)+1;
      //  cout<<v<<endl;
     // cout<<v<<" "<<k<<endl;
        printf("%d\n",max(r[u][k],r[v-m2[k]+1][k]));
    }
}
