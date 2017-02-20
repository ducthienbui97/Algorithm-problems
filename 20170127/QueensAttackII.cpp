#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> > blocked;
int n;
int X[8]={1,1,1,-1,-1,-1,0,0};
int Y[8]={-1,1,0,1,-1,0,1,-1};
int go(int x,int y,int dx,int dy){
    if(x>n||y>n||x<1||y<1) return 0;
    if(blocked.find(make_pair(x,y))!=blocked.end()) return 0;
    return go(x+dx,y+dy,dx,dy)+1;
}
main(){
    ios_base::sync_with_stdio(false);
    int x,y,k;
    cin >> n >> k;
    cin >> x >> y;
    for(int i=0;i<k;i++){
        int tx,ty;
        cin>>tx>>ty;
        blocked.insert(make_pair(tx,ty));
    }
    int ans = 0;
    for(int i=0;i<8;i++)
        ans += go(x+X[i],y+Y[i],X[i],Y[i]);
    cout << ans <<endl;
}
