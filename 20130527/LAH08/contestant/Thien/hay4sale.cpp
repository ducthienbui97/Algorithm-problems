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
const int Maxn=50000+10;
bool A[Maxn];
int F[5555];
main(){
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int n,c;
    scanf("%d%d",&c,&n);
    A[0]=true;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&F[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=c;j>=F[i];j--)
    {
        if(A[j-F[i]]) {A[j]=true,ans=max(ans,j);}
    }
    printf("%d",ans);
}
