#include <bits/stdc++.h>
#define elif else if
using namespace std;
int H[333][333];
int _H[333][333];
char c[333][333];
int M[333];
int n,m;
int getH(int x,int l,int r,int t){
    return H[x][r]-H[x][l-1]*M[t];
}
int get_H(int x,int l,int r,int t){
    return _H[x][r]-_H[x][l+1]*M[t];
}
bool find(int x,int y,int t){
    int h=0,_h=0;
    for(int i=x;i<x+t;i++){
        h=h*M[t]+getH(i,y,y+t-1,t);
    }
    for(int i=x+t-1;i>=x;i--){
    _h=_h*M[t]+get_H(i,y+t-1,y,t);

    }
    return (h==_h);
}
bool check(int t){
    for(int i=1;i+t-1<=n;i++)
        for(int j=1;j+t-1<=m;j++)
        if(find(i,j,t)) return true;
    return false;
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>&c[i][1];
    M[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            H[i][j]=H[i][j-1]*5+(c[i][j]-'0'+1);
            }
        for(int j=m; j>0; j--) {
            _H[i][j]=_H[i][j+1]*5+(c[i][j]-'0'+1);
            }
        }
    for(int i=1;i<=300;i++)
        M[i]=M[i-1]*5;
    for(int i=min(n,m); i>1; i--)
        if(check(i)) {
            printf("%d",i);
            return 0;
            }
    printf("-1");
    }
