#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <climits>
#define X first
#define Y second
#define input "CUBE.INP"
#define output "CUBE.OUT"
#define int long long
using namespace std;
typedef pair<int,int> Int;
const int Maxn=1e5+20;
void openfile(){
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
}
int a[6],b[6],c[6];
int cal(int x[],int y[]){
    int d[6];
    for(int i=0;i<3;i++)
        d[i]=max(x[i],y[i]);
    for(int i=3;i<6;i++)
        d[i]=min(x[i],y[i]);
    for(int i=0;i<3;i++)
        d[i]=max(d[i+3]-d[i],0LL);
    return d[0]*d[1]*d[2];
}

int cal(int x[],int y[],int z[]){
    int d[6];
    for(int i=0;i<3;i++)
        d[i]=max(z[i],max(x[i],y[i]));
    for(int i=3;i<6;i++)
        d[i]=min(z[i],min(x[i],y[i]));
    for(int i=0;i<3;i++)
        d[i]=max(d[i+3]-d[i],0LL);
    return d[0]*d[1]*d[2];
}
main(){
    int n;
    #ifndef HYQ
        openfile();
    #endif
    ios_base::sync_with_stdio(false);
    for(int i=0;i<6;i++)
        cin>>a[i];
    for(int i=0;i<3;i++)
        if(a[i]>a[i+3]) swap(a[i],a[i+3]);
    for(int i=0;i<6;i++)
        cin>>b[i];
    for(int i=0;i<3;i++)
        if(b[i]>b[i+3]) swap(b[i],b[i+3]);
    for(int i=0;i<6;i++)
        cin>>c[i];
    for(int i=0;i<3;i++)
        if(c[i]>c[i+3]) swap(c[i],c[i+3]);
    int ans=0;
    ans+=(a[3]-a[0])*(a[4]-a[1])*(a[5]-a[2]);
    ans+=(b[3]-b[0])*(b[4]-b[1])*(b[5]-b[2]);
    ans+=(c[3]-c[0])*(c[4]-c[1])*(c[5]-c[2]);
    ans-=cal(a,b);
    ans-=cal(b,c);
    ans-=cal(a,c);
    ans+=cal(a,b,c);
    cout<<ans<<endl;
}
