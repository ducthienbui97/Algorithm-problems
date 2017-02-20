#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<deque>
#include<map>
#include<set>
#define oo 1000000000
#define ooll 1ll<<50
#define base 1000000007ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
                            /*                           END OF TEMPLATE                            */

int BIT[1025][1025],n;
void update(int u,int v,int w)
{
    for(int i=u; i<=n; i+=i&(-i))
        for(int j=v; j<=n; j+=j&(-j)) BIT[i][j]+=w;
}
int query(int u,int v)
{
    int ans=0;
    for(int i=u; i>=1; i=i&(i-1))
        for(int j=v; j>=1; j=j&(j-1)) ans+=BIT[i][j];
    return ans;
}
int main()
{
    freopen("mobiles.inp","r",stdin);
    freopen("mobiles.out","w",stdout);
    int t,a,b,x,y,w;
    scanf("%d %d",&t,&n);
    while(1)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %d %d",&a,&b,&w);
            update(a+1,b+1,w);
        }
        if(t==2)
        {
            scanf("%d %d %d %d",&a,&b,&x,&y); a++; b++; x++; y++;
            printf("%d\n",query(x,y)+query(a-1,b-1)-query(a-1,y)-query(x,b-1));
        }
        if(t==3) return 0;
    }
    return 0;
}
