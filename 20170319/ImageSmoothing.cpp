// https://www.hackerearth.com/challenge/competitive/march-circuits-17/problems/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int> > F,G,newG;
    int n,m;
    cin >> n >> m;
    F.resize(2*m+1,vector<int>(2*m+1));
    G.resize(n,vector<int>(n));
    newG.resize(n,vector<int>(n,0));
    for(int i = -m;i <= m; i++)
        for(int j = -m; j <= m; j++)
            cin >> F[i+m][j+m];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin >> G[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        for(int ii=-m;ii<=m;ii++)
        if(i+ii <n&&i+ii>=0)
            for(int jj=-m;jj<=m;jj++)
            if(j+jj < n && j + jj >= 0)
            newG[i][j] += G[i+ii][j+jj]*F[ii+m][jj+m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << newG[i][j]<<" ";
        cout <<endl;
    }
}
