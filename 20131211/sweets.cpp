#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#define mp make_pair
#define elif else if
#define ss first.first
#define pp first.second
#define kk second
using namespace std;
const int Maxn=600000;
template <class T> void getmax(T& x,T y){if(x<y) x=y;}
typedef pair<pair<long long,long long>,bool  >  query;
int a[30];
vector<query> Q;

void bt(int now,int to,long long a1,long long a2,long long a3,bool KK){
    if(now>to){
        query ad;
        ad.ss=a1-a2;
        ad.pp=a2-a3;
        ad.kk=KK;
        if(!KK){
            ad.ss=-ad.ss;
            ad.pp=-ad.pp;
        }
        Q.push_back(ad);
        return;
    }
    bt(now+1,to,a1+a[now],a2,a3,KK);
    bt(now+1,to,a1,a2+a[now],a3,KK);
    bt(now+1,to,a1,a2,a3+a[now],KK);
}
int n;
long long S[Maxn];
void update(int ix,long long val){
    for(;ix<Maxn;ix+=ix&(-ix)) getmax(S[ix],val);
}
long long get(int ix){
    long long s=-(1ll<<60);
    for(;ix>0;ix-=ix&(-ix)) getmax(s,S[ix]);
    return s;
}
vector<long long> cpr;
main(){
    ios_base::sync_with_stdio(false);
    memset(S,-0x3f,sizeof S);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bt(1,(n+1)>>1,0,0,0,0);
    bt(((n+1)>>1)+1,n,0,0,0,1);
    sort(Q.begin(),Q.end());
    for(int i=0;i<Q.size();i++){
       if(!Q[i].kk) cpr.push_back(Q[i].pp);
    }
    sort(cpr.begin(),cpr.end());
    cpr.resize(unique(cpr.begin(),cpr.end())-cpr.begin());
    long long ans=1ll<<60;
    for(int i=0;i<Q.size();i++){
        if(!Q[i].kk){
            update(upper_bound(cpr.begin(),cpr.end(),Q[i].pp)-cpr.begin(),Q[i].ss+Q[i].pp);
        }
        else  ans=min(ans,Q[i].ss+Q[i].pp-get(upper_bound(cpr.begin(),cpr.end(),Q[i].pp)-cpr.begin()));
    }
    cout<<ans<<endl;
}
