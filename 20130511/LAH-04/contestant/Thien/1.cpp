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
main()
{
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    int a[11111];
    int n;
    int x,y;
    int j=0,l;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&y);
        a[x]=y;
    }
    int k;
    bool ch;
    while(scanf("%d%d",&x,&y)!=EOF&&x&&y)
    {
        ch=false;
        k=a[x];
        j=0;
        while(k!=x)
        {
            if(j>n) break;
            if(k==y)
            {
                ch=true;
                l=j;
            }
            j++;
            k=a[k];
        }
        if(!ch) printf("No\n");
        else printf("Yes %d\n",l);
    }
}
