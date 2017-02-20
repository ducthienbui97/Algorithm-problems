#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>
#include <cstring>
#include <climits>
#include <ctime>
#include <queue>
#include <map>
#include <set>
using namespace std;
int sum[505];
main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    sum[0]=0;
    int n,q,h,f,l;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&h);
        sum[i]=sum[i-1]+h;
    }
    for(int i=1; i<=q; i++)
    {
        scanf("%d%d",&f,&l);
        printf("%d\n",sum[l]-sum[f-1]);
    }
}
