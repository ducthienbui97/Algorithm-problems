#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pi;
pi root[1111][1111];
int c[1111][1111];
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};
int n,m;
pi findroot(const pi& x){
    if(root[x.X][x.Y].first<0) return x;
    else return root[x.X][x.Y]=findroot(root[x.X][x.Y]);
}
void uni(pi x,pi y){
    x=findroot(x);
    y=findroot(y);
    if(x==y) return;
    root[x.X][x.Y].first+=root[y.X][y.Y].first;
    root[y.X][y.Y]=x;
}
vector<pair<pi,pi> > ed,edg;
vector<pi> R1;
vector<pi> R2;
vector<int> id;
vector<pi> tt;
inline pi T(const pair<pi,pi>& x){
    return pi(c[x.X.X][x.X.Y],c[x.Y.X][x.Y.Y]);
}
bool cmp(int x,int y){
    return tt[x]<tt[y];
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>c[i][j],root[i][j]=pi(-1,0);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        for(int k=0;k<4;k++){
            if(i+xx[k]<=0||i+xx[k]>n) continue;
            if(j+yy[k]<=0||j+yy[k]>m) continue;
            if(c[i+xx[k]][j+yy[k]]==c[i][j]) uni(pi(i,j),pi(i+xx[k],j+yy[k]));
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        for(int k=0;k<4;k++){
            if(i+xx[k]<=0||i+xx[k]>n) continue;
            if(j+yy[k]<=0||j+yy[k]>m) continue;
            if(c[i+xx[k]][j+yy[k]]>c[i][j]){
                    ed.push_back(make_pair(findroot(pi(i,j)),findroot(pi(i+xx[k],j+yy[k]))));
                    id.push_back(id.size());
                    tt.push_back(T(ed.back()));
            }
        }
    }
    R1.resize(ed.size());
    R2.resize(ed.size());
    edg.resize(ed.size());
    sort(id.begin(),id.end(),cmp);
    for(int i=0;i<id.size();i++)
        edg[i]=ed[id[i]];
    int ans=0;
    for(int i=0;i<edg.size();i++){
        int j=i;
        while(j+1<edg.size()&&T(edg[j+1])==T(edg[i]))++j;
        for(int k=i;k<=j;k++){
            R1[k]=root[edg[k].X.X][edg[k].X.Y];
            R2[k]=root[edg[k].Y.X][edg[k].Y.Y];
        }
        for(int k=i;k<=j;k++) uni(edg[k].X,edg[k].Y);
        for(int k=i;k<=j;k++){
            pi tmp=findroot(edg[k].X);
            ans=max(ans,-root[tmp.X][tmp.Y].first);
            root[edg[k].X.X][edg[k].X.Y]=R1[k];
            root[edg[k].Y.X][edg[k].Y.Y]=R2[k];
        }
        i=j;
    }
    printf("%d",ans);
}

/*
5 6
1 1 1 1 3 1
2 3 4 5 4 1
1 2 1 2 5 1
6 7 8 1 6 2
1 1 2 1 6 6
*/
