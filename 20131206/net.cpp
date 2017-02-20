#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
int F[36][400000];
bool done[36][400000];
int n,m;
int rr;
vector<int> x;
vector<int> y;
int findroot(vector<int>& root,int u){
    if(root[u-1]==u) return u;
    return root[u-1]=findroot(root,root[u-1]);
}
int hashtb(vector<int>& d){
    int rep=0;
    for(int i=1;i<=n;i++){
        rep*=i;
        rep+=findroot(d,i)-1;
    }
    return rep;
}
int need;
vector<int> R;
int f(int now,vector<int> d){
   int tmp=hashtb(d);
    if(now==m) return tmp==rr;
    if(done[now][tmp]) return F[now][tmp];
    done[now][tmp]=true;
    F[now][tmp]+=f(now+1,d);
    int xx=findroot(d,x[now]);
    int yy=findroot(d,y[now]);
    if(xx>yy) swap(xx,yy);
    d[yy-1]=xx;
    F[now][tmp]+=f(now+1,d);
    return F[now][tmp];
}

main() {
    ios_base::sync_with_stdio (false);
    cin>>n>>m;
    x.resize(m);
    y.resize(m);
    R.resize(n);
    for(int i=0;i<n;i++)
        R[i]=i+1;
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
       int  xx=findroot(R,x[i]);
        int yy=findroot(R,y[i]);
        if(xx>yy) swap(xx,yy);
        R[yy-1]=xx;
    }
    rr=hashtb(R);
    for(int i=0;i<n;i++)
        R[i]=i+1;
    cout<<f(0,R);
}
