// https://www.hackerearth.com/challenge/competitive/march-circuits-17/problems/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > p[1000001];
int V[1111][1111];
int main(){
    ios_base::sync_with_stdio(false);
    long long n,m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j++){
            p[i*j].push_back(make_pair(j,i));
            cin >> V[i][j];
            sum += V[i][j] - 1;
            V[i][j] = 1;
        }
    }
    for(int i=n*n;i>0;i--){
        for(int j=0;j<p[i].size();j++){
            int x=p[i][j].first;
            int y=p[i][j].second;
            V[x][y] += min(m-1,sum);
            sum -= min(m-1,sum);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << V[i][j] <<' ';
        cout <<endl;
    }
}
