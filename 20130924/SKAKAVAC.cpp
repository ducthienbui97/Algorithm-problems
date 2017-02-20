#include <bits/stdc++.h>
using namespace std;
#define elif else if
const int Maxn=1555;
int c[Maxn][Maxn][2];
int h[Maxn][Maxn][2];
int a[Maxn][Maxn];
int F[Maxn*Maxn];
int cont[1000111];
int st[1000111];
int n;
pair<int,int> vs[3000333];
int geth(int u,int T,bool cc) {
    int ans=0;
    while(u>0){
        ans=max(ans,h[T][u][cc]);
        u-=u&(-u);
    }
    return ans;
}

int getc(int u,int T,bool cc) {
    int ans=0;
    while(u>0){
        ans=max(ans,c[T][u][cc]);
        u-=u&(-u);
    }
    return ans;
}
void updateh(int u,int T,bool cc,int val) {
    while(u<Maxn){
        h[T][u][cc]=max(h[T][u][cc],val);
        u+=u&(-u);
    }
}
void updatec(int u,int T,bool cc,int val) {
    while(u<Maxn){
        c[T][u][cc]=max(c[T][u][cc],val);
        u+=u&(-u);
    }
}
int Max;
bool cmp(const pair<int,int>& x ,const pair<int,int>& y) {
    return a[x.first][x.second]<a[y.first][y.second];
    }
int cnt;
void Sort(const int& x,const int& y){
    for(int i=a[x][y]+1;i<=1000000;i++){
        st[i]=cnt;
        cnt+=cont[i];
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]>a[x][y]){
                vs[st[a[i][j]]++]=make_pair(i,j);
            }
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>n;
    int x,y;
    cin>>x>>y;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
            }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            if(a[i][j]>a[x][y])
                cont[a[i][j]]++;
        }
    Sort(x,y);
    int ans=1;
    updatec(x,y,0,1);
    updateh(y,x,0,1);
    updatec(n+1-x,y,1,1);
    updateh(n+1-y,x,1,1);
    for(int i=0; i<cnt; ) {
        int j=i;
        while(j+1<cnt&&a[vs[j+1].first][vs[j+1].second]==a[vs[i].first][vs[i].second]) j++;
        j++;
        for(int l=i; l<j; l++) {
             x=vs[l].first;
             y=vs[l].second;
            int C=max(max(getc(x-2,y-1,0),getc(n+1-(x+2),y-1,1)),max(getc(x-2,y+1,0),getc(n+1-(x+2),y+1,1)));
            int H=max(max(geth(y-2,x-1,0),geth(n+1-(y+2),x-1,1)),max(geth(y-2,x+1,0),geth(n+1-(y+2),x+1,1)));
            if(!H&&!C) continue;
            ans=max(ans,F[l]=max(H,C)+1);
            }
        while(i<j){
            x=vs[i].first;
            y=vs[i].second;
            updatec(x,y,0,F[i]);
            updateh(y,x,0,F[i]);
            updatec(n+1-x,y,1,F[i]);
            updateh(n+1-y,x,1,F[i]);
            i++;
        }
    }
    printf("%d",ans);
    }

/*
5
3 3
20 16 25 17 12
11 13 13 30 17
15 29 10 26 11
27 19 14 24 22
23 21 28 18 13
*/
