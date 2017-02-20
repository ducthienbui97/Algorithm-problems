#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <utility>
#define elif else if
#define X first
#define Y second
using namespace std;
const long long int Maxt=1e12;
const int Maxn=5e4+20;
long long int mid,n,m,r,l,kx,ans;
long long int t[Maxn],p[Maxn],a[Maxn];
bool check(long long int k){
    long long int j;
    long long int z;
    for(int i=1;i<=n;i++){
    z=k-t[i];
    j=0;
        if(z>=0) {
            j+=((z/p[i])+1);
        }
    a[i]=-j;
    }
    sort(a+1,a+n+1);
    j=0;
    for(int i=1;i<=m;i++)
    j+=a[i];
    if(abs(j)>=kx) return true;
    else return false;
}
main(){
    scanf("%lld%lld%lld",&n,&m,&kx);
    for(int i=1;i<=n;i++)
        scanf("%lld",&t[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    l=0;
    r=Maxt;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%lld",ans);
}
