#include <bits/stdc++.h>

using namespace std;
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};
double R[666][666],H[666][666];
double distances[666][666];
int n,m,p;
vector<pair<int,int> > v;
double cal(int x1,int y1,int x2,int y2){
    return (R[x1][y1] + R[x2][y2])/2*exp(3.5*abs((H[x2][y2] - H[x1][y1])/10 + 0.05));
}
double dist(int x1,int y1,int x2,int y2){
    priority_queue<pair<double,pair<int,int> >, vector<pair<double,pair<int,int> > >, greater<pair<double,pair<int,int> > > > pr;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            distances[i][j] = 2e9;
    pr.push({0.,{x1,y1}});
    distances[x1][y1] = 0;
    while(!pr.empty()){
        double dis = pr.top().first;
        int x = pr.top().second.first;
        int y = pr.top().second.second;
        pr.pop();
        if(dis > distances[x][y])
            continue;
        for(int i = 0 ; i < 4; i++){
            if(x + X[i] < 0 || x + X[i] >= n) continue;
            if(y + Y[i] < 0 || y + Y[i] >= m) continue;
            double tmp = dis + cal(x,y,x+X[i],y+Y[i]);
            if(distances[x + X[i]][y + Y[i]] > tmp){
                distances[x + X[i]][y + Y[i]] = tmp;
                pr.push({tmp, {x+X[i],y+Y[i]}});
            }
        }
    }
    return distances[x2][y2];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    v.resize(p + 1);
    for(auto&u:v) cin >> u.first >> u.second;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> R[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> H[i][j];
        }

    double ans = 0;
    for(int i = 1; i <= p; i++)
        ans += dist(v[i-1].first, v[i-1].second, v[i].first, v[i].second);
    cout << ceil(ans);
}


