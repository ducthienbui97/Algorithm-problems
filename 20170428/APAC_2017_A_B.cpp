#include <bits/stdc++.h>
using namespace std;
int H[111][111];
int sz[111][111];
pair<int,int> R[111][111];
set<pair<int,pair<int,int> > > nei[111][111];
vector<pair<int,pair<int,int> > > v;
int X[4] = {1,-1,0,0};
int Y[4] = {0,0,1,-1};
pair<int,int> findr(int x,int y){
    if(R[x][y] != make_pair(x,y)) R[x][y] = findr(R[x][y].first,R[x][y].second);
    return R[x][y];
}
void solve(int nTest){
    v.clear();
    int ans = 0;
    int n,m;
    cin >> n >>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            nei[i][j].clear();
            cin >> H[i][j];
            R[i][j] = make_pair(i,j);
            sz[i][j] = 1;
            v.push_back(make_pair(H[i][j],make_pair(i,j)));
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int dir = 0; dir < 4; dir++){
                if(i + X[dir] > 0 && i + X[dir] <= n && j + Y[dir] > 0 && j + Y[dir] <= m)
                    nei[i][j].insert(make_pair(H[i+X[dir]][j+Y[dir]],make_pair(i+X[dir],j+Y[dir])));
                else nei[i][j].insert(make_pair(0,make_pair(0,0)));
                }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int xx,yy;
        int h = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        while(!nei[x][y].empty()){
            xx = nei[x][y].begin()-> second.first;
            yy = nei[x][y].begin()-> second.second;
            if(findr(xx,yy) == v[i].second) nei[x][y].erase(nei[x][y].begin());
            else if(findr(xx,yy) != nei[x][y].begin() -> second){
                nei[x][y].insert(make_pair(H[R[xx][yy].first][R[xx][yy].second],R[xx][yy]));
                nei[x][y].erase(make_pair(H[xx][yy],make_pair(xx,yy)));
            }else break;
        }
        if(H[xx][yy] >= H[x][y]){
            ans += sz[x][y]*(H[xx][yy]-H[x][y]);
            R[x][y] = make_pair(xx,yy);
            sz[xx][yy] += sz[x][y];
            for(auto value:nei[x][y])
                nei[xx][yy].insert(value);
        }else{
            continue;
        }
    }
    cout <<"Case #"<<nTest<<": "<<ans<<endl;
}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}

