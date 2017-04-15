#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[111][111];
char ans[111][111];
int cnt[111][111];
int count(int x1,int y1,int x2,int y2){
    return cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1];
}
void find(int x1,int y1,int x2,int y2){
    if(count(x1,y1,x2,y2) == 1){
        char v;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                if(s[i][j]!='?') v = s[i][j];
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                ans[i][j] = v;

        return;
    }
    for(int x3=x1;x3<x2;x3++)
    if(count(x1,y1,x3,y2) && count(x3+1,y1,x2,y2)){ // (x1,y1) -> (x3,y2) (x3+1,y1) -> (x2,y2)
        find(x1,y1,x3,y2);
        find(x3+1,y1,x2,y2);
        return;
    }
    for(int y3=y1;y3<y2;y3++)
    if(count(x1,y1,x2,y3) && count(x1,y3+1,x2,y2)){ // (x1,y1) -> (x2,y3) (x1,y3+1) -> (x2,y2)
        find(x1,y1,x2,y3);
        find(x1,y3+1,x2,y2);
        return;
    }
}
void solve(int nTest){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> (&s[i][1]);
        ans[i][m+1]=0;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cnt[i][j] = cnt[i-1][j] + cnt[i][j-1]-cnt[i-1][j-1]+(s[i][j]!='?');
    find(1,1,n,m);
    cout << "Case #"<<nTest<<":\n";
    for(int i=1;i<=n;i++)
        cout <<(&ans[i][1])<<endl;
}

main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
