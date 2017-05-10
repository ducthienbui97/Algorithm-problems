#include <bits/stdc++.h>
using namespace std;
int love[100];
int mp[111][111];
int X[] = {0,1,0,-1};
int Y[] = {1,0,-1,0};
pair<pair<int,int>,int> px[111];
char C[111][111];
int n,m;
bool ok(){
    int t = 2*n + 2*m;
    for(int i=1;i<=t;i++){
        int x = px[i].first.first;
        int y = px[i].first.second;
        int d = px[i].second;
        //cout << x << " "<<y<<" "<<d<<endl;
        while(x>0&&x<=n&&y>0&&y<=m){
            if(C[x][y] == '/'){
                d ^= 3;
            }else{
                d ^= 1;
            }
            x += X[d];
            y += Y[d];
        }
        //cout <<x <<" "<<y <<" "<<d <<" "<<mp[x][y]<<endl;
        if(mp[x][y] != love[i]) return false;

    }
    return true;
}
void solve(int nTest){
    cin >> n >> m;
    for(int i=0;i<n+m;i++){
        int x,y;
        cin >> x >> y;
        love[x] = y;
        love[y] = x;
    }
    memset(C,0,sizeof C);
    cout << "Case #"<<nTest<<":\n";
    int cnt = 0;
    for(int i=1;i<=m;i++) {
        mp[0][i] = ++cnt;
        px[cnt] = make_pair(make_pair(1,i),1);
    }
    for(int i=1;i<=n;i++){
        mp[i][m+1] = ++cnt;
        px[cnt] = make_pair(make_pair(i,m),2);
    }
    for(int i=m;i>0;i--){
        mp[n+1][i] = ++cnt;
        px[cnt] = make_pair(make_pair(n,i),3);
    }
    for(int i=n;i>0;i--){
        mp[i][0] = ++cnt;
        px[cnt] = make_pair(make_pair(i,1),0);
    }
    for(int i=0;i<(1<<(n*m));i++){
        for(int c=0;c<(n*m);c++){
            int x = c/m + 1;
            int y = c%m + 1;
            if(i&(1<<c)) C[x][y] = '\\';
            else C[x][y] = '/';
        }
        if(ok()){
            for(int i=1;i<=n;i++)
                cout << (&C[i][1]) <<endl;
            return;
        }
    }
    cout <<"IMPOSSIBLE\n";
}
main(){
    freopen("C-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}


