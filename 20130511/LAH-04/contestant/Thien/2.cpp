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
#include <stack>
#define elif else if
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
long long int a[11111];
int n,t;
int x,y;
vector <int> d[11111];
main()
{

    freopen("2.inp","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d",&n);
    while(scanf("%d%d",&x,&y)!=EOF&&x&&y)
    {
        if(x>y)
        {
            t=x;
            x=y;
            y=t;
        }
        d[y].push_back(x);
    }
    a[1]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<d[i].size(); j++)
        {
            a[i]+=a[d[i][j]];
        }
    }
    printf("%lld",a[n]);
}
