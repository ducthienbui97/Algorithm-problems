#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define elif else if
#define int long long
#define input "ssmedian.inp"
#define output "ssmedian.out"
using namespace std;
inline void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
const int Maxn=1e5+10;
int s[Maxn];
int Sum[Maxn];
vector<int> d;
void update(int x){
    while(x<Maxn){
        s[x]++;
        x+=x&-x;
    }
}
int get(int x){
    int S=0;
    while(x>0){
        S+=s[x];
        x-=x&-x;
    }
    return S;
}
main() {
#ifdef HYQ
    openfile();
#endif
    ios_base::sync_with_stdio(false);
    int n,X,x;
    cin>>n>>X;
    d.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x<X) Sum[i]=Sum[i-1]-1;
        else Sum[i]=Sum[i-1]+1;
        d.push_back(Sum[i]);
    }
    sort(d.begin(),d.end());
    int t=lower_bound(d.begin(),d.end(),0)-d.begin()+1;
    update(t);
    int ans=0;
    for(int i=1;i<=n;i++){
        t=lower_bound(d.begin(),d.end(),Sum[i])-d.begin()+1;
        ans+=get(t);
        update(t);
    }
    cout<<ans<<endl;
}
