#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define X first
#define Y second
#define elif else if
#define PB push_back
#define MP make_pair
#define inc(_x,_n) _x=(_x+a)%b,_n++
#define input "values11.inp"
#define output "values11.out"
using namespace std;
const long long Maxn=1e4+10;
bool vs[Maxn];
long long Min[Maxn];
void pre(){
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
}
main()
{
    pre();
    ios_base :: sync_with_stdio(false);
    long long a,b,c;
    cin>>a>>b>>c;
    if(a>b) swap(a,b);
    long long x=a;
    long long now=1;
    while(!vs[x]&&now<=c)
    {
        //cout<<x<<endl;
        vs[x]=true;
        Min[x]=now;
        inc(x,now);
    }
    long long ans=0;
    long long Max=b*c;
    ans=c;
    for(long long i=1; i<b; i++)
    {
        if(vs[i])
        {
        	//cout<<i<<endl;
            ans+=(c-Min[i])+1;
        }
    }
    cout<<ans<<endl;
}
