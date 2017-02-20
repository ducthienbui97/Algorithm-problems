#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define elif else if
#define input "nnegpart.inp"
#define output "nnegpart.out"
using namespace std;
inline void openfile(){
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
}
const int Maxn=1e5+10;
int r=1e9+9;
int s[Maxn],sum[Maxn];
vector<int> d;
void update(int x,int val){
    while(x<Maxn){
        s[x]=(s[x]+val)%r;
        x+=x&-x;
    }
}
int get(int x){
    int S=0;
    while(x>0){
        S=(S+s[x])%r;
        x-=x&-x;
    }
    return S;
}
main() {
    #ifndef HYQ
    openfile();
    #endif
    ios_base::sync_with_stdio(false);
    int n;
    int x;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>x;
        sum[i]=sum[i-1]+x;
        d.push_back(sum[i]);
        }
    int ans=0;
    sort(d.begin(),d.end());
    update(lower_bound(d.begin(),d.end(),0)-d.begin()+1,1);
    for(int i=1;i<=n;i++){
        int t=lower_bound(d.begin(),d.end(),sum[i])-d.begin()+1;
        ans=get(t);
        update(t,ans);
        }
    printf("%d",ans);
    }
