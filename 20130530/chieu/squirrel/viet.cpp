#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#define oo 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
                            /*                           END OF TEMPLATE                            */

vector<long long> T,P;
int M,N;
long long K;
bool check(long long mid)
{
    int i,j;
    long long ans=0;
    priority_queue<long long, vector<long long>, less<long long> > pq;
    for(i=0; i<M; i++)
    {
        long long x=mid-T[i];
        if(x>=0) x=x/P[i]+1;
        pq.push(x);
    }
    for(i=1; i<=N; i++)
    {
        ans+=pq.top();
        pq.pop();
    }
    if(ans>=K) return true;
    return false;
}
int main()
{
    freopen("squirrel.inp","r",stdin);
    freopen("squirrel.out","w",stdout);
    int i;
    scanf("%d %d %lld",&M,&N,&K);
    T.assign(M,0);
    P.assign(M,0);
    for(i=0; i<M; i++) cin>>T[i];
    for(i=0; i<M; i++) cin>>P[i];
    long long low=0ll,high=(1ll<<63)-1;
    do
    {
        long long mid=(low+high)/2ll;
        if(check(mid)) high=mid;
        else low=mid;
    } while(low+1<high);
    if(check(low)) cout<<low;
    else cout<<high;
    return 0;
}
